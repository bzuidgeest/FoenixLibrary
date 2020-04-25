
#ifndef SOUND_H
#define SOUND_H

//$AF:E600..$AF:E7FF 	OPL3 
#define OPL3	((volatile unsigned char *)0xAFE600)


#define writeOPL3(register, data) (OPL3[register] = data)
//void writeOPL3(unsigned char register, unsigned char data);

#endif /* SOUND_H */
