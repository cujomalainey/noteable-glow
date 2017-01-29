CXXFLAGS=-Wall -O3 -g -fno-strict-aliasing

all:
	gcc main.cpp serial.cpp audio.pb.c proto_packer.cpp lib/pb_common.c lib/pb_encode.c -lm -lpthread -lstdc++ -lbass $(CXXFLAGS) -Ilib/ -Llib/ -I.
