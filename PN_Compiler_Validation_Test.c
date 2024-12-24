#include <stdint.h>
int main()
{
    //IP State
    uint64_t* IP_State_Addr = (uint64_t*) 0x0000000000000080;//状态寄存器基址
    //MEM IP
    uint64_t* MEM_Addr = (uint64_t*) 0x0000000000000090;//MEM寄存器基址
    //MLP IP
    uint64_t* MLP_Addr = (uint64_t*) 0x00000000000000a0;//MLP寄存器基址
    //Subsample IP
    uint64_t* SUB_Addr = (uint64_t*) 0x00000000000000b0;//SUB寄存器基址
    //Grouping IP
    uint64_t* GRP_Addr = (uint64_t*) 0x00000000000000c0;//GRP寄存器基址
    //Reduction IP
    uint64_t* REC_Addr = (uint64_t*) 0x00000000000000d0;//REC寄存器基址
    //CPU 总线宽度偏移
    uint64_t OFFSET = (uint64_t) 0x0000000001000000;//64;
    ///////////////////////////////////////片外数据加载/////////////////////////////////////////////
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待; 
    * MEM_Addr = 0x1111111111111111;//CPU宽度1
    * (MEM_Addr+OFFSET) = 0x1111111111111111;//CPU宽度2
    
    //////////////////////////////////////L1 MLP////////////////////////////////////////////////////
    while(!(*IP_State_Addr&0x0000000000000002)){};//查询等待
    * MLP_Addr = 0x0000000000000090;//
    * (MLP_Addr+OFFSET) = 0x0000000000000090;//
    
    //////////////////////////////////////L2 Set Abstraction////////////////////////////////////////
    while(!(*IP_State_Addr&0x0000000000000004)){};//查询等待
    * SUB_Addr = 0x0000000000000090;
    * (SUB_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000004)){};//查询等待
    * GRP_Addr = 0x0000000000000090;
    * (GRP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000008)){};//查询等待
    * REC_Addr = 0x0000000000000090;
    * (REC_Addr+OFFSET) = 0x0000000000000090;
    
    //////////////////////////////////////L2 InvResMLP////////////////////////////////////////////////
    while(!(*IP_State_Addr&0x0000000000000004)){};//查询等待
    * GRP_Addr = 0x0000000000000090;
    * (GRP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000008)){};//查询等待
    * REC_Addr = 0x0000000000000090;
    * (REC_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;
    
    //////////////////////////////////////L3 Set Abstraction////////////////////////////////////////
    while(!(*IP_State_Addr&0x0000000000000004)){};//查询等待
    * SUB_Addr = 0x0000000000000090;
    * (SUB_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000004)){};//查询等待
    * GRP_Addr = 0x0000000000000090;
    * (GRP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000008)){};//查询等待
    * REC_Addr = 0x0000000000000090;
    * (REC_Addr+OFFSET) = 0x0000000000000090;
    
    //////////////////////////////////////L3 InvResMLP////////////////////////////////////////////////
    while(!(*IP_State_Addr&0x0000000000000004)){};//查询等待
    * GRP_Addr = 0x0000000000000090;
    * (GRP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000008)){};//查询等待
    * REC_Addr = 0x0000000000000090;
    * (REC_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;
    //////////////////////////////////////L4 Set Abstraction////////////////////////////////////////
    while(!(*IP_State_Addr&0x0000000000000004)){};//查询等待
    * SUB_Addr = 0x0000000000000090;
    * (SUB_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000004)){};//查询等待
    * GRP_Addr = 0x0000000000000090;
    * (GRP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000008)){};//查询等待
    * REC_Addr = 0x0000000000000090;
    * (REC_Addr+OFFSET) = 0x0000000000000090;

     //////////////////////////////////////L4 InvResMLP////////////////////////////////////////////////
    while(!(*IP_State_Addr&0x0000000000000004)){};//查询等待
    * GRP_Addr = 0x0000000000000090;
    * (GRP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000008)){};//查询等待
    * REC_Addr = 0x0000000000000090;
    * (REC_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;
    
    //////////////////////////////////////L5 Set Abstraction////////////////////////////////////////
    while(!(*IP_State_Addr&0x0000000000000004)){};//查询等待
    * SUB_Addr = 0x0000000000000090;
    * (SUB_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000004)){};//查询等待
    * GRP_Addr = 0x0000000000000090;
    * (GRP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000008)){};//查询等待
    * REC_Addr = 0x0000000000000090;
    * (REC_Addr+OFFSET) = 0x0000000000000090;

     //////////////////////////////////////L5 InvResMLP////////////////////////////////////////////////
    while(!(*IP_State_Addr&0x0000000000000004)){};//查询等待
    * GRP_Addr = 0x0000000000000090;
    * (GRP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000008)){};//查询等待
    * REC_Addr = 0x0000000000000090;
    * (REC_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;
    
    while(!(*IP_State_Addr&0x0000000000000001)){};//查询等待
    * MLP_Addr = 0x0000000000000090;
    * (MLP_Addr+OFFSET) = 0x0000000000000090;

    return 0;
}