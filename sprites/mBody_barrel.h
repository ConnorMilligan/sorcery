char const *mBody_barrelName = "Barrel";

int mBody_barrelWidth = 32;
int mBody_barrelHeight = 64;

char const *mBody_barrelSprite =
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````````"
	"````````````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````````"
	"````````````````!!!!````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````!!!!````````````"
	"````````````````!!!!````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````!!!!````````````"
	"````````````````````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!````!!!!!!!!!!!!````````````````!!!!````````````"
	"````````````````````````````````!!!!!!!!````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!````````!!!!!!!!!!!!!!!!!!!!````````!!!!````````````"
	"````````````````````!!!!!!!!!!!!!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!````````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!````````````!!!!!!!!!!!!````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````"
	"````````````````````````!!!!!!!!!!!!!!!!````````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````!!!!!!!!!!!!!!!!!!!!````````````````````"
	"````````````!!!!!!!!!!!!!!!!````````````````````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!````````````````````!!!!````````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````````````````````````````"
	"````````````````````````````````````!!!!````````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````````````````````````````"
	"````````````````````````````!!!!````!!!!````````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````````````````````````````"
	"````````````````````````````!!!!````````````````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````````````````````````````"
	"````````````````````````````````````````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!````````````````````````````````````````````````````"
	"````````````````````````````````````````````!!!!````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````"
	"````````````````````````````````````````!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!````````````!!!!!!!!````````````````````````````````````"
	"````````````````````````````````!!!!!!!!````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!````````!!!!!!!!````````````````````````````````"
	"````````````````````!!!!!!!!!!!!!!!!````!!!!!!!!````!!!!!!!!!!!!"
	"!!!!!!!!````!!!!!!!!!!!!````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!````````!!!!!!!!!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!````````````!!!!!!!!!!!!!!!!!!!!````````````````````````"
	"````````````!!!!!!!!!!!!!!!!!!!!!!!!````````````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!````````````````````````!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````````````````````````````"
	"````````````````````````````````````````!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````````````````````````````"
	"````````````````````````````````````````!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````````````````````````````"
	"````````````````````````````````````````!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````````````````````````````"
	"````````````````````````````````!!!!````!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````````````````````````````"
	"````````````````````````````````!!!!````!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````````````````````````````"
	"````````````````````````````````!!!!````!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````````````````````````````"
	"````````````````````````````````!!!!````!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````````````````````````````"
	"````````````````````````````````!!!!````!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````````````````````````````"
	"````````````````````````````````!!!!````!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!````````````````````````````````````````````````````"
	"````````````````````````````!!!!````````!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!````!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````!!!!````````!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!````!!!!````````````````````````````````````````````"
	"````````````````````````````````````````!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!````!!!!````````````````````````````````````````````"
	"````````````````````````````````````````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!````!!!!!!!!````````````````````````````````````````"
	"````````````````````````````````````````````!!!!````!!!!!!!!!!!!"
	"!!!!!!!!!!!!````````!!!!!!!!````````````````````````````````````"
	"````````````````````````````````````````!!!!!!!!````!!!!!!!!!!!!"
	"!!!!!!!!!!!!````````````!!!!!!!!````````````````````````````````"
	"````````````````````````````````````!!!!!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````!!!!!!!!````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````!!!!!!!!!!!!!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````"
	"````````````````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"";
