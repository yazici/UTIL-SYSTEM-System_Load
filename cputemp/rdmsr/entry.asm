;
;    OS/4 RDMSR$
;
;    Copyright (c) OS/4 Team 2016
;    All Rights Reserved
;    컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
;
;   driver header and standard entry points
;
                   .686P
                   .SEQ
                   include segments.inc
                   include ddk/devhdr.inc
                   include macro.inc
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
                   Extrn Dos32FlatDS:ABS
                   Extrn Strat_Init_:Far
                   Extrn DriverEntry:Near
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
_DDHEADER          Segment                                           ;
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
Public             _MainEntry                                        ;
                   dd    -1                                          ; NextHdr
                   dw    DEV_CHAR_DEV+DEVLEV_3                       ; DrvFlags
_MainEntry         dw    _TEXT16:Strat_Init_                         ;
                   dw    0                                           ; IDCEntry
                   db    'RDMSR$  '                                  ; DriverName
                   dw    0                                           ; ProtCS
                   dw    0                                           ; ProtDS
                   dw    0                                           ; RealCS
                   dw    0                                           ; RealDS
                   dd    DEV_INITCOMPLETE+DEV_ADAPTER_DD+DEV_16MB+DEV_IOCTL2; Capabilities
                   dw    0                                           ; Rsvd
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
_DDHEADER          EndS                                              ;
; 袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴�
_TEXT16            Segment                                           ;
                   Assume ds:_DDHEADER,es:NOTHING                    ;
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
; 16-bit strategy                                                    ;
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
Public             _Strat16                                          ;
_Strat16           Proc  Far                                         ;
                   jmp   Far Ptr FLAT:g_Strategy32                   ;
_Strat16           EndP                                              ;
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
_TEXT16            EndS                                              ;
; 袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴�
_TEXT              Segment                                           ;
                   Assume ds:_DDHEADER,es:NOTHING                    ;
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
; 32-bit part of Strategy entry thunk                                ;
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
g_Strategy32       Proc    Far
                   SaveReg <ax,ds,es>
                   db      66h
                   push    es
                   push    bx
                   SetFlat32 <ds,es>,ax
                   call    DriverEntry
                   add     esp, 4
                   RestReg <es,ds,ax>
                   db      66h
                   retf
g_Strategy32       EndP
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
_TEXT              EndS                                              ;
; 袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴袴�
_TEXTEND           Segment                                           ;
                   Public  _CodeEnd                                  ;
_CodeEnd           Label   Byte                                      ;
_TEXTEND           EndS                                              ;
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
                   END
