CC = g++
LD = g++
AR = ar

CFLAGS = -Os
LDFLAGS = 

OUTPUT = libmathexpr.a
OBJS = MathExpr/MathExpr.o

$(OUTPUT): $(OBJS)
	$(AR) -r $@ $< 

clean: 
	rm -f $(OBJS) $(OUTPUT)

%.o: %.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

