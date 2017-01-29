CXXFLAGS=-Wall -O3 -g -fno-strict-aliasing

all:
	gcc main.cpp serial.cpp audio.pb.c proto_packer.cpp bass_handler.cpp lib/pb_common.c lib/pb_encode.c -lm -lstdc++ -lbass $(CXXFLAGS) -Ilib/ -Llib/ -I.
