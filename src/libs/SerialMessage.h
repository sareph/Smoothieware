#ifndef SERIALMESSAGE_H
#define SERIALMESSAGE_H

#include <string>

#include <StreamOutput.h>

struct SerialMessage {
        StreamOutput* stream;
        std::string message;
		
		void ack(int ln)
		{
			stream->printf("ok");
			
			if (ln)
			{
				stream->printf(" %d", ln);
			}
			
			stream->printf("\r\n");
		};

};
#endif
