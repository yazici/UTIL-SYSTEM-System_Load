;
;    OS/4 RDMSR$
;
;    Copyright (c) OS/4 Team 2016
;    All Rights Reserved
;   컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
;
;
;
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
; 뫌魚젺���� 誓（飡昔�
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
SaveReg            Macro   Which                                     ;
                   irp     y,<Which>                                 ; 쵟む�� � 쵟む�醒 �젳´設猶좐蟯� ㏇� 졷ｃД�瞬
                       push y                                        ;
                   EndM                                              ;
EndM
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
; 궙遜�젺�˙���� 誓（飡昔�
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
RestReg            Macro   Which                                     ;
                   irp     y,<Which>                                 ; 쵟む�� � 쵟む�醒 �젳´設猶좐蟯� ㏇� 졷ｃД�瞬
                       pop y                                         ;
                   EndM                                              ;
EndM
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
; 뫌魚젺���� 誓（飡昔� ㄻ� � �留�쥯
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
SaveCRegs          Macro
                   SaveReg <ds,es,ebx,edi,esi,ebp>
EndM
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
; 궙飡젺�˙���� 誓（飡昔� ㄻ� � �留�쥯
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
RestCRegs          Macro
                   RestReg <ebp,esi,edi,ebx,es,ds>
EndM
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
; 볚�젺�˚�  FLAT 췅 誓（飡贍 (32 〃�)
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
SetFlat32          Macro   Who, How                                  ;
                   mov     How, offset Dos32FlatDS                   ;
                   irp y,<Who>                                       ; 쵟む�� � 쵟む�醒 �젳´設猶좐蟯� ㏇� 졷ｃД�瞬
                       mov y,e&How                                   ;
                       assume y:FLAT                                 ;
                   EndM                                              ;
EndM
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
; wasm �洙젳젷碎 ％��黍筍  call far32 ptr
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
callfar32          Macro  Target
                   db 9Ah
                   dd offset Target
                   dw seg _TEXT16
EndM
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
; Device Helpers
; 컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
DevHlp_Save_Message     equ  61
MsgTable  struc
MsgID     dw  ?
NumItem   dw  ?
PtrItem   dd  ?
MsgTable  ends
MSG_REPLACEMENT_STRING  equ  1178
