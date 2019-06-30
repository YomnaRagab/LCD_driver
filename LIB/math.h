#ifndef MATH1
#define MATH1
#include "../LIB/locations.h"
#define SET(REGi, pinNoi) REGi |=  (1 << (pinNoi))
#define CLR(REGi, pinNOi)  REGi &= ~(1<< pinNOi)
#define TOG(REGi, pinNOi)  REGi ^= (1<< pinNOi)
#define GET(VAR, BITNO) (((VAR) >> (BITNO)) & 0x01)
#define SETPORT(PORT) do{ SET(PORT,0);\
                          SET(PORT,1);\
                          SET(PORT,2);\
                          SET(PORT,3);\
                          SET(PORT,4);\
                          SET(PORT,5);\
                          SET(PORT,6);\
                          SET(PORT,7);\
                            }while(0)
#define CLRPORT(PORT) do{ CLR(PORT,0);\
                          CLR(PORT,1);\
                          CLR(PORT,2);\
                          CLR(PORT,3);\
                          CLR(PORT,4);\
                          CLR(PORT,5);\
                          CLR(PORT,6);\
                          CLR(PORT,7);\
                        }while(0)

#define GETPORT(PORT) do{ GET(PORT,0);\
                          GET(PORT,1);\
                          GET(PORT,2);\
                          GET(PORT,3);\
                          GET(PORT,4);\
                          GET(PORT,5);\
                          GET(PORT,6);\
                          GET(PORT,7);\
                        }while(0)

#define TOGPORT(PORT) do{ TOG(PORT,0);\
                          TOG(PORT,1);\
                          TOG(PORT,2);\
                          TOG(PORT,3);\
                          TOG(PORT,4);\
                          TOG(PORT,5);\
                          TOG(PORT,6);\
                          TOG(PORT,7);\
                        }while(0)

#endif
