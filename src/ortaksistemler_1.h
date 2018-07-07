// ortak olarak kullan?lan tanim ve nesneler

typedef struct {
 union {
  uint8_t Paket[20];
 };
} ULTRASONAR;
ULTRASONAR Ultrasonar;
extern ULTRASONAR Ultrasonar;