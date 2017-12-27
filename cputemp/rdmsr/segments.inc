;
;    OS/4 RDMSR$
;
;    Copyright (c) OS/4 Team 2016
;    All Rights Reserved
;   ���������������������������������������
;
;   declaration and ordering of driver segments
;
_DDHEADER          Segment Dword Public USE16 'DATA'
_DDHEADER          EndS
; ���������������������������������������������������������������������������
CONST              Segment Dword Public USE32 'DATA'
CONST              EndS
; ���������������������������������������������������������������������������
CONST2             Segment Dword Public USE32 'DATA'
CONST2             EndS
; ���������������������������������������������������������������������������
_DATA              Segment Dword Public USE32 'DATA'
_DATA              EndS
; ���������������������������������������������������������������������������
_BSS               Segment Dword Public USE32 'BSS'
_BSS               EndS
; ���������������������������������������������������������������������������
DGROUP             GROUP _DDHEADER,CONST,CONST2,_DATA,_BSS


; ���������������������������������������������������������������������������
_TEXT16            Segment Para  Public USE16 'CODE'
_TEXT16            EndS
; ���������������������������������������������������������������������������
_TEXT              Segment Dword Public USE32 'CODE'
_TEXT              EndS
; ���������������������������������������������������������������������������
_TEXTEND           Segment Byte  Public USE32 'CODE'
_TEXTEND           EndS
; ���������������������������������������������������������������������������
_TEXTINIT          Segment Dword Public USE32 'CODE'
_TEXTINIT          EndS
; ���������������������������������������������������������������������������
CGROUP             GROUP _TEXT16,_TEXT,_TEXTEND,_TEXTINIT