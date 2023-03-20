#ifndef DIO_H_
#define DIO_H_

typedef enum{FALSE,TRUE}; bool;
	
#define setBit(REG,P) (REG |= (1<<P))
#define clearBit(REG,P) (REG &= ~(1<<P))
	
void DIO_setPinDir(char PORTT, int PINN, bool i_o);
void DIO_setPortDir(uint8_t PORTT,uint8_t Val);
void DIO_writePort(uint8_t PORTT,uint8_t Val);
void DIO_writePin(uint8_t PORTT,uint8_t PINN,bool i_o);
void DIO_WriteHighNibble(uint8_t PORTT,uint8_t data);
bool DIO_readPin(uint8_t PORTT,uint8_t PINN);
uint8_t DIO_readPort(uint8_t PORTT,uint8_t PINN);

#endif