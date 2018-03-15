/* Define header for application - AppBuilder 2.03  */

#if defined(__cplusplus)
extern "C" {
#endif

/* 'base' Window link */
extern const int ABN_base;
#define ABW_base                             AbGetABW( ABN_base )
extern const int ABN_TextLog;
#define ABW_TextLog                          AbGetABW( ABN_TextLog )
extern const int ABN_ButtonConnect;
#define ABW_ButtonConnect                    AbGetABW( ABN_ButtonConnect )
extern const int ABN_ButtonDisconnect;
#define ABW_ButtonDisconnect                 AbGetABW( ABN_ButtonDisconnect )

#define AbGetABW( n ) ( AbWidgets[ n ].wgt )

#define AB_OPTIONS "s:x:y:h:w:S:"

#if defined(__cplusplus)
}
#endif

