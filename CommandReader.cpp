#include "S2Library.h"

void ReadCommand()
{
	while (true)
	{
		/* Command Buffer */
		char* Command = new char[16];

		/* Reset Command Index */
		*(WORD*)0x009025F4 = 0x00;

		/* Read Command and Take Action */
		memcpy(Command, (void*)0x009020F4, 16);
		std::string pCommand(Command);

		/* Check Command Flag "/" */
		if (Command[0] == 47)
		{
			/* Interpret Commands */
			if (pCommand.find("/command") != std::string::npos)
			{
				try
				{
					ShowGameMessage("Commands and BCM Working.", 0x00, 0x01);
				}
				catch (...) {}
			}

			/* Reset Command Text */
			memset(Command, 0x00, 16);
			memcpy((void*)0x009020F4, &Command, 16);
		}

		Sleep(10);
	}
}