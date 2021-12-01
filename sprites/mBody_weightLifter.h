char const *mBody_weightLifterName = "Weight-lifting";

int mBody_weightLifterWidth = 32;
int mBody_weightLifterHeight = 64;

char const *mBody_weightLifterSprite =
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
	"!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````"
	"````````````````````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!````````````````````````````````````````!!!!!!!!"
	"````````````````!!!!!!!!````````````````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!````````````````````````````````````!!!!!!!!!!!!````"
	"````````````````````!!!!!!!!````````````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!````````````````````````````````````````````````````"
	"````````````````````````````````````````````````````````!!!!!!!!"
	"!!!!!!!!!!!!````````````````````!!!!````````````````````````````"
	"````````````````````````````````!!!!````````````````````!!!!!!!!"
	"!!!!!!!!````````````!!!!````````!!!!!!!!````````````````````````"
	"````````````````````````````````!!!!!!!!````````````````````!!!!"
	"!!!!!!!!````````!!!!!!!!!!!!````````!!!!````````````````````````"
	"````!!!!````````````````````````!!!!````````````````````````!!!!"
	"!!!!!!!!````````````!!!!````````````!!!!````````````````!!!!````"
	"````!!!!````````!!!!````````````!!!!````````````````````````!!!!"
	"!!!!!!!!````!!!!````!!!!````!!!!````!!!!````````````````````````"
	"````!!!!````````````````````````!!!!````````````!!!!````````!!!!"
	"!!!!!!!!````````!!!!!!!!!!!!````````!!!!````````!!!!!!!!!!!!!!!!"
	"````````````!!!!!!!!!!!!!!!!````!!!!````````!!!!!!!!````````!!!!"
	"!!!!!!!!!!!!````````````````````!!!!!!!!````````````````````````"
	"````````````````````````````````!!!!!!!!````!!!!````````````!!!!"
	"!!!!!!!!!!!!````````````````!!!!!!!!!!!!````````````!!!!!!!!!!!!"
	"````````````!!!!!!!!!!!!````````!!!!!!!!!!!!````````````!!!!!!!!"
	"!!!!!!!!!!!!````````````````!!!!!!!!!!!!````````````````````````"
	"````````````````````````````````!!!!!!!!!!!!````````````!!!!!!!!"
	"!!!!!!!!````````````````````````!!!!!!!!````````````!!!!!!!!!!!!"
	"!!!!!!!!````!!!!!!!!````````````!!!!!!!!!!!!````````````````!!!!"
	"!!!!!!!!````````````````````````!!!!!!!!````````````````!!!!````"
	"````!!!!!!!!````````````````````!!!!!!!!````````````````````!!!!"
	"!!!!!!!!````````````````````````````!!!!!!!!````````````!!!!````"
	"````````!!!!!!!!````````````````````!!!!````````````````````!!!!"
	"!!!!!!!!!!!!````````````````````````````!!!!!!!!!!!!!!!!````````"
	"````````!!!!!!!!````````````````````!!!!````````!!!!````````!!!!"
	"!!!!!!!!!!!!!!!!````````````````````````````````````````````````"
	"````````!!!!````````````````````!!!!!!!!````````!!!!````````!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````````````````"
	"````!!!!!!!!````````````````````!!!!!!!!````````!!!!````````!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````!!!!!!!!````````````!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````````"
	"````````````````````````````````````!!!!!!!!````````````!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````````"
	"````````````````````````````````````!!!!````````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!````````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````!!!!!!!!"
	"````````````````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````!!!!````````````````````````"
	"!!!!````````````````````!!!!````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````!!!!````````````````````!!!!"
	"!!!!!!!!````````````````!!!!````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````!!!!````````````````````!!!!"
	"!!!!!!!!````````````!!!!!!!!````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````!!!!!!!!````````````````!!!!"
	"!!!!!!!!!!!!````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````!!!!"
	"!!!!!!!!!!!!````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````!!!!"
	"!!!!!!!!!!!!````````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````````!!!!!!!!"
	"!!!!!!!!!!!!````````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!````````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!````````````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!!!!!````````````````````````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````!!!!!!!!!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````````!!!!!!!!!!!!"
	"!!!!!!!!!!!!!!!!!!!!````````````````````````````!!!!!!!!!!!!!!!!"
	"";
