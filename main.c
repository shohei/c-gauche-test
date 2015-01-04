#include <stdio.h>
#include <gauche.h>


#define PRINT_EXCEPTION(packet) \
    printf("[%s] %s\n", \
           SCM_STRING_CONST_CSTRING(Scm_ConditionTypeName(packet.exception)), \
           SCM_STRING_CONST_CSTRING(Scm_ConditionMessage(packet.exception)));


void load()
{
    ScmLoadPacket load_packet;
    Scm_AddLoadPath(".", TRUE);
    if(Scm_Load("url.scm", 0, &load_packet) < 0) {
        PRINT_EXCEPTION(load_packet);
        return;
    }
}
 
int main()
{
    GC_INIT();
    Scm_Init(GAUCHE_SIGNATURE);
    load();
    printf("OK\n");
    return 0;
}

