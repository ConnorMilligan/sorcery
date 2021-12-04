char const *mBody_fridgeName = "Fridge";

int mBody_fridgeWidth = 32;
int mBody_fridgeHeight = 64;

char const *mBody_fridgeSprite =
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
	"````````````````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````"
	"````````````````````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````"
	"````````````````````````````````````````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````!!!!!!!!!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````````"
	"````````````````````````````````!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````````"
	"````````````````````````````````!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````!!!!!!!!!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````````````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````````````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````````````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````````````"
	"````````````````````````!!!!!!!!!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````````"
	"````````````````````````````````!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````!!!!!!!!!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````````````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````````"
	"````````````````````````````````````````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````"
	"````````````````````````````````````````````!!!!!!!!!!!!!!!!!!!!"
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
	"";
