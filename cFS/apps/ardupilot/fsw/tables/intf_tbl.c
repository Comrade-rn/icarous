
#include "cfe.h"
#include "cfe_tbl_filedef.h"  /* Required to obtain the CFE_TBL_FILEDEF macro definition */
#include "ardupilot_table.h"
#include "ardupilot.h"

#ifdef SITL

ArdupilotTable_t TblStruct = {
	SOCKET,    // apPortType
	0,           // baudrate
	14551,       // apPortin
	0,           // apPortout
	"127.0.0.1", // ap address
	SOCKET,    // gsPortType
	0,           // baudrate
	14552,       // gsPortin
	14553,       // gsPortout
	"127.0.0.1"  // gs address
};

#else
ArdupilotTable_t TblStruct = {
        SERIAL,       // apPortType
        57600,          // baudrate
        0,              // apPortin
        0,              // apPortout
        "/dev/ttyACM0", // ap address
        SERIAL,       // gsPortType
        57600,          // baudrate
        0,              // gsPortin
        0,              // gsPortout
        "/dev/ttyUSB0"  // gs address
};
#endif


/*
** The macro below identifies:
**    1) the data structure type to use as the table image format
**    2) the name of the table to be placed into the cFE Table File Header
**    3) a brief description of the contents of the file image
**    4) the desired name of the table image binary file that is cFE compatible
*/
CFE_TBL_FILEDEF(TblStruct, ARDUPILOT.InterfaceTable, Interface parameters, intf_tbl.tbl )
