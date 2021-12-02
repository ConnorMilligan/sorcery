char const *mBody_clownName = "Clownly";

int mBody_clownWidth = 32;
int mBody_clownHeight = 64;

char const *mBody_clownSprite =
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
	"!!!!!!!!!!!!!!!!!!!!!!!!````!!!!!!!!````````````````````````````"
	"````````````!!!!````````!!!!````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!````````````!!!!!!!!````!!!!````````````!!!!!!!!"
	"````````````!!!!````````!!!!!!!!````!!!!!!!!````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!````````````````````!!!!!!!!!!!!````````````!!!!!!!!"
	"````````!!!!!!!!````````!!!!!!!!!!!!!!!!````!!!!````!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````!!!!!!!!````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````!!!!!!!!"
	"!!!!!!!!````````````````````!!!!````````````!!!!!!!!!!!!````````"
	"````!!!!!!!!````````````````````````!!!!````````````````!!!!!!!!"
	"!!!!````````````````````!!!!!!!!````````````````````````````!!!!"
	"!!!!````````````````````````````!!!!!!!!!!!!````````````````!!!!"
	"!!!!````````````````````!!!!!!!!````````````````````````````!!!!"
	"!!!!````````````````````````````!!!!!!!!!!!!!!!!````````````````"
	"!!!!````````````````!!!!!!!!!!!!````````````````````````````````"
	"````````````````````````````````!!!!!!!!!!!!!!!!!!!!````````````"
	"!!!!````````````````!!!!!!!!!!!!````````````````````````````````"
	"````````````````````````````````!!!!!!!!!!!!!!!!!!!!````````````"
	"!!!!````````````````!!!!!!!!!!!!````````````````````````````````"
	"````````````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!````````"
	"!!!!````````````!!!!!!!!!!!!!!!!!!!!````````````````````````!!!!"
	"!!!!````````````````````````````!!!!!!!!!!!!!!!!!!!!````````````"
	"!!!!````````````!!!!!!!!!!!!!!!!!!!!````````````````````````!!!!"
	"!!!!!!!!````````````````````!!!!!!!!!!!!!!!!!!!!````````````````"
	"!!!!````````````````!!!!!!!!!!!!!!!!!!!!````````````````````!!!!"
	"!!!!!!!!````````````````````!!!!!!!!!!!!!!!!````````````````````"
	"!!!!````````````````!!!!!!!!!!!!!!!!!!!!````````````````````````"
	"!!!!````````````````````!!!!!!!!!!!!````````````````````````!!!!"
	"!!!!!!!!````````````````!!!!!!!!!!!!````````````````````````````"
	"````````````````````````!!!!!!!!!!!!!!!!````````````````````!!!!"
	"!!!!!!!!````````````````!!!!!!!!!!!!!!!!!!!!````````````````````"
	"````````````````````````````!!!!````!!!!!!!!````````````!!!!!!!!"
	"!!!!!!!!````````!!!!!!!!!!!!!!!!!!!!````!!!!!!!!````````````````"
	"````````````````````````!!!!!!!!````````!!!!````````````!!!!!!!!"
	"!!!!!!!!````!!!!!!!!!!!!````!!!!!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!````````````````!!!!````````````````````````````"
	"````````````````!!!!!!!!````!!!!!!!!````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!````````````````!!!!!!!!!!!!````````!!!!````````````"
	"````````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````!!!!!!!!!!!!!!!!````````!!!!````````````"
	"````````````````!!!!````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````!!!!!!!!````````````"
	"````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````"
	"!!!!!!!!````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````"
	"!!!!!!!!````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````"
	"!!!!!!!!````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````"
	"!!!!!!!!````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````!!!!"
	"!!!!!!!!````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````!!!!"
	"!!!!!!!!````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````!!!!"
	"!!!!!!!!````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````!!!!"
	"!!!!!!!!````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````!!!!"
	"!!!!!!!!````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````"
	"!!!!!!!!!!!!````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````"
	"!!!!!!!!!!!!````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````!!!!"
	"!!!!!!!!!!!!````````````!!!!!!!!!!!!!!!!!!!!!!!!````````!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````!!!!"
	"!!!!!!!!!!!!````````````!!!!!!!!!!!!!!!!!!!!````````````````!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````!!!!"
	"!!!!!!!!````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!````````````````!!!!!!!!!!!!!!!!!!!!!!!!````````!!!!"
	"!!!!````````!!!!````!!!!!!!!!!!!!!!!!!!!!!!!````````````````````"
	"!!!!!!!!!!!!````````````````````````````````````````````````!!!!"
	"!!!!````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````"
	"!!!!!!!!````````````````````````````````````````````````````!!!!"
	"!!!!````````````!!!!!!!!!!!!!!!!````````````````````````````!!!!"
	"!!!!!!!!````````````````````````````````````````````````````!!!!"
	"!!!!!!!!````````````````````````````````````````````````````!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````````````````````````````!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!````````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!"
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
