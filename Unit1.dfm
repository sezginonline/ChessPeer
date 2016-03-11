object Form1: TForm1
  Left = 537
  Top = 129
  Width = 280
  Height = 119
  Caption = 'Connection'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 272
    Height = 33
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 8
      Width = 54
      Height = 13
      Caption = 'IP Address:'
    end
    object Button2: TButton
      Left = 186
      Top = 3
      Width = 75
      Height = 25
      Caption = 'Connect'
      TabOrder = 0
      OnClick = Button2Click
    end
    object Edit1: TEdit
      Left = 72
      Top = 4
      Width = 105
      Height = 21
      TabOrder = 1
    end
  end
  object Button1: TButton
    Left = 8
    Top = 48
    Width = 121
    Height = 25
    Caption = 'Wait for Connection'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 152
    Top = 48
    Width = 113
    Height = 25
    Caption = 'Reset Connection'
    TabOrder = 2
    OnClick = Button3Click
  end
end
