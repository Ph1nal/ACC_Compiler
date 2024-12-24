#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
//#include <iostream>

//Model Structure
#define NUM_LAYER 5 // 模型层数 

// Memory Module
#define NUM_BANKS 16     // bank数量
#define BANK_SIZE 8192   // bank大小（Bytes）
#define MEM_SIZE NUM_BANKS*BANK_SIZE //MEM总计大小
// IP
#define NUM_IP 1 // 卷积IP

const int  mm_size= NUM_BANKS*BANK_SIZE; //memory size

//训练模型数据结构

//MLP
uint16_t N_Pnt_M[5]={1024,256,64,32,16};//1+4×4
uint16_t Channel_M[5]={32,3,3,3,3};       
//Subsample
uint16_t N_Pnt_S[5]={1024,256,64,32,16};//0+1×4
uint16_t Channel_S[5]={32,3,3,3,3};
//Grouping
uint16_t N_Pnt_G[5]={1024,256,64,32,16};//0+2×4
uint16_t Channel_G[5]={32,3,3,3,3};
//Reduction
uint16_t N_Pnt_G[5]={1024,256,64,32,16};//0+2×4
uint16_t Channel_G[5]={32,3,3,3,3};

//Input
const N_In = 10;
uint16_t Input[10][3]={{6,3,2},{6,3,2},{6,3,2},{6,3,2},{6,3,2},{6,3,2},{6,3,2},{6,3,2},{6,3,2},{6,3,2}};//10 points×3 channel

//IP调用信息存储
uint32_t MLP[1+4*NUM_LAYER][4];//Layer×(N_Point+Channel+[IFM_Addr+OFM_Addr]);
uint32_t Subsample[0+NUM_LAYER][4];
uint32_t Grouping[0+2*NUM_LAYER][4];
uint32_t Reduction[0+2*NUM_LAYER][4];

//convolution
uint16_t N_Pnt[5]={1024,256,64,32,16};
uint16_t N_Filter[5]={9,16,16,25,49};
uint16_t Channel[5]={3,3,3,3,3};

const int N_In = 5;
const int N_Fi = 4;
uint16_t Input[5][5]={{6,3,2,3,1},{6,3,2,3,1},{6,3,2,3,1},{6,3,2,3,1},{6,3,2,3,1}};
uint16_t Filter[5][4]={{3,3,2,3},{6,3,2,3},{6,3,2,3},{6,3,2,3},{6,3,2,3}};

uint32_t Convolution[5];

// Bank Memory管理
uint8_t Bank[MEM_SIZE];//Bank存储模拟
uint8_t Bank_Memory_Chart[MEM_SIZE];//Bank状态表

// 各IP处理数据存储起始的物理地址映射 
uint32_t IP_Addr_Chart[4][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};//各IP状态信息：IFM_Addr，OFM_Addr，Calculate State

// Load() IP：从外部存储器读取指定的数据到内存中的指定地址
void Load(int value, int *address) {
    //实现Load IP功能
    *address = value; // 将 value 存储到 address 指向的位置
}

typedef struct MemoryBlock {
    uint32_t  size;           // 内存块的大小
    uint8_t *addr_start;
    //uint8_t *addr_end;
    //uint8_t *addr;
    struct MemoryBlock *next; // 下一个内存块
} MemoryBlock;

typedef struct MemoryQueue {
    MemoryBlock *head;    // 队列的头指针
    MemoryBlock *tail;    // 队列的尾指针
} MemoryQueue;

// 内存块入队
void enqueueMemoryBlock(MemoryQueue *memoryQueue ,uint8_t *addr_start, uint32_t size) {
    MemoryBlock *newBlock = (MemoryBlock *)malloc(sizeof(MemoryBlock));
    newBlock->size = size;  
    newBlock->addr_start = addr_start;
    //newBlock->addr_end = addr_end;
    //newBlock->addr = addr;
    newBlock->next = NULL;

    //队列维护
    if (memoryQueue->tail) {
        memoryQueue->tail->next = newBlock;
        //memoryQueue->tail = newBlock;
    } else {
        memoryQueue->head = newBlock;
    }
    memoryQueue->tail = newBlock;
}

// 内存块出队
void dequeueMemoryBlock(MemoryQueue *memoryQueue, int size) {

    // 获取头部块
    MemoryBlock *dequeuedBlock = memoryQueue->head;

    while (dequeuedBlock!=NULL)
    {
        if (size <= dequeuedBlock->size)
        {
            dequeuedBlock->size -= size;      // 块大小扣除
            dequeuedBlock->addr_start + size; // 起始偏移
            break;
        }
        else
        {
            dequeuedBlock = dequeuedBlock->next;
        }
    }

    if(dequeuedBlock==NULL)
    {
        //存放在外部

        //内存紧凑


    }

    // 利用完的块移出队列
    while (memoryQueue->head->size == 0) 
    {
        memoryQueue->head =  memoryQueue->head ->next;//移出队列
    }

    return;
}

int main()
{
    //BankMemory存储模拟
    uint8_t Bank[MEM_SIZE];
    
    //内存队列初始化
    MemoryQueue memoryQueue;
    memoryQueue.head=NULL;
    memoryQueue.tail=NULL;

    //内存初始化BankMenmory加载
    enqueueMemoryBlock(&memoryQueue, &Bank[0], MEM_SIZE);

    // convolution
    dequeueMemoryBlock(&memoryQueue, 3+N_Pnt[0]* Channel[0]+N_Filter[0]);
    Load(3+N_Pnt[0]* Channel[0]+N_Filter[0], memoryQueue.head) ;
    
    //Convolution IP
    Convolution[0] = N_Pnt[0];    // N_pnt
    Convolution[1] = N_Filter[0]; // N_Filter
    Convolution[2] = Channel[0];  // Channel
    Convolution[3] = memoryQueue.head; // IFM_Addr
    Convolution[4] = memoryQueue.head; // Filter_Addr
    Convolution[5] = memoryQueue.head; // OFM_Addr

    return 0;
}