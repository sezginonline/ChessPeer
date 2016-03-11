object MDIChild: TMDIChild
  Left = 205
  Top = 295
  Width = 742
  Height = 641
  Caption = 'Game Board'
  Color = clBtnFace
  ParentFont = True
  FormStyle = fsMDIChild
  Icon.Data = {
    0000010001002020100001000400E80200001600000028000000200000004000
    0000010004000000000000020000000000000000000010000000000000000000
    0000000080000080000000808000800000008000800080800000C0C0C0008080
    80000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000000000000000000077777777777777777777777777777700788
    88888FFFFFFF8888888FFFFFFF70078888888FFFFFFF8888888FFFFFFF700788
    88888FFFFFFF8888888FFFFFFF70078888888FFFFFFF8888888FFFFFFF700788
    88888FFFFFFF8888888FFFFFFF70078888888FFFFFFF8888888FFFFFFF700788
    88888FFFFFFF8888888FFFFFFF7007FFFFFFF8888888FFFFFFF88888887007FF
    FFFFF8888888FFFFFFF88888887007FFFFFFF8888888FFFFFFF88888887007FF
    FFFFF8888888FFFFFFF88888887007FFFFFFF8888888FFFFFFF88888887007FF
    FFFFF8888888FFFFFFF88888887007FFFFFFF8888888FFFFFFF8888888700788
    88888FFFFFFF8888888FFFFFFF70078888888FFFFFFF8888888FFFFFFF700788
    88888FFFFFFF8888888FFFFFFF70078888888FFFFFFF8888888FFFFFFF700788
    88888FFFFFFF8888888FFFFFFF70078888888FFFFFFF8888888FFFFFFF700788
    88888FFFFFFF8888888FFFFFFF7007FFFFFFF8888888FFFFFFF88888887007FF
    FFFFF8888888FFFFFFF88888887007FFFFFFF8888888FFFFFFF88888887007FF
    FFFFF8888888FFFFFFF88888887007FFFFFFF8888888FFFFFFF88888887007FF
    FFFFF8888888FFFFFFF88888887007FFFFFFF8888888FFFFFFF8888888700777
    7777777777777777777777777770000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000}
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object LeftPanel: TPanel
    Left = 0
    Top = 0
    Width = 504
    Height = 511
    Align = alLeft
    Color = clWhite
    TabOrder = 0
    object SqDark: TImage
      Left = 331
      Top = 440
      Width = 60
      Height = 60
      Visible = False
    end
    object SqLight: TImage
      Left = 395
      Top = 440
      Width = 60
      Height = 60
      Visible = False
    end
    object TheBorderImage2: TImage
      Left = 8
      Top = 72
      Width = 60
      Height = 60
    end
    object TheBorderImage1: TImage
      Left = 8
      Top = 8
      Width = 60
      Height = 60
    end
    object a8: TImage
      Left = 23
      Top = 0
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object b8: TImage
      Left = 83
      Top = 0
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object c8: TImage
      Left = 143
      Top = 0
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object d8: TImage
      Left = 203
      Top = 0
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object e8: TImage
      Left = 263
      Top = 0
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object f8: TImage
      Left = 323
      Top = 0
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object g8: TImage
      Left = 383
      Top = 0
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object h8: TImage
      Left = 443
      Top = 0
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object g7: TImage
      Left = 383
      Top = 60
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object b7: TImage
      Left = 83
      Top = 60
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object c7: TImage
      Left = 143
      Top = 60
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object d7: TImage
      Left = 203
      Top = 60
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object e7: TImage
      Left = 263
      Top = 60
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object f7: TImage
      Left = 323
      Top = 60
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object h7: TImage
      Left = 443
      Top = 60
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object a7: TImage
      Left = 23
      Top = 60
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object b5: TImage
      Left = 83
      Top = 180
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object a5: TImage
      Left = 23
      Top = 180
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object h6: TImage
      Left = 443
      Top = 120
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object g6: TImage
      Left = 383
      Top = 120
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object f6: TImage
      Left = 323
      Top = 120
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object e6: TImage
      Left = 263
      Top = 120
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object d6: TImage
      Left = 203
      Top = 120
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object c6: TImage
      Left = 143
      Top = 120
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object b6: TImage
      Left = 83
      Top = 120
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object g5: TImage
      Left = 383
      Top = 180
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object h5: TImage
      Left = 443
      Top = 180
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object f5: TImage
      Left = 323
      Top = 180
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object e5: TImage
      Left = 263
      Top = 180
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object d5: TImage
      Left = 203
      Top = 180
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object c5: TImage
      Left = 143
      Top = 180
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object a6: TImage
      Left = 23
      Top = 120
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object b3: TImage
      Left = 83
      Top = 300
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object a3: TImage
      Left = 23
      Top = 300
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object h4: TImage
      Left = 443
      Top = 240
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object g4: TImage
      Left = 383
      Top = 240
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object f4: TImage
      Left = 323
      Top = 240
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object e4: TImage
      Left = 263
      Top = 240
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object d4: TImage
      Left = 203
      Top = 240
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object a2: TImage
      Left = 23
      Top = 360
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object b1: TImage
      Left = 83
      Top = 420
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object c1: TImage
      Left = 143
      Top = 420
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object c4: TImage
      Left = 143
      Top = 240
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object d1: TImage
      Left = 203
      Top = 420
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object e1: TImage
      Left = 263
      Top = 420
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object f1: TImage
      Left = 323
      Top = 420
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object h1: TImage
      Left = 443
      Top = 420
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object g1: TImage
      Left = 383
      Top = 420
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object b2: TImage
      Left = 83
      Top = 360
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object c2: TImage
      Left = 143
      Top = 360
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object d2: TImage
      Left = 203
      Top = 360
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object e2: TImage
      Left = 263
      Top = 360
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object f2: TImage
      Left = 323
      Top = 360
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object b4: TImage
      Left = 83
      Top = 240
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object g2: TImage
      Left = 383
      Top = 360
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object h2: TImage
      Left = 443
      Top = 360
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object a1: TImage
      Left = 23
      Top = 420
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object g3: TImage
      Left = 383
      Top = 300
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object h3: TImage
      Left = 443
      Top = 300
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object f3: TImage
      Left = 323
      Top = 300
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object e3: TImage
      Left = 263
      Top = 300
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object d3: TImage
      Left = 203
      Top = 300
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object c3: TImage
      Left = 143
      Top = 300
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object a4: TImage
      Left = 23
      Top = 240
      Width = 60
      Height = 60
      Transparent = True
      OnDragDrop = xyDragDrop
      OnDragOver = xyDragOver
      OnMouseDown = xyMouseDown
      OnStartDrag = xyStartDrag
    end
    object Label1: TLabel
      Left = 46
      Top = 480
      Width = 13
      Height = 27
      Caption = 'a'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 106
      Top = 480
      Width = 14
      Height = 27
      Caption = 'b'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 166
      Top = 480
      Width = 12
      Height = 27
      Caption = 'c'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 226
      Top = 480
      Width = 14
      Height = 27
      Caption = 'd'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 286
      Top = 480
      Width = 13
      Height = 27
      Caption = 'e'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 346
      Top = 480
      Width = 7
      Height = 27
      Caption = 'f'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 406
      Top = 480
      Width = 14
      Height = 27
      Caption = 'g'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label8: TLabel
      Left = 466
      Top = 480
      Width = 14
      Height = 27
      Caption = 'h'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label9: TLabel
      Left = 3
      Top = 435
      Width = 13
      Height = 27
      Caption = '1'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label10: TLabel
      Left = 3
      Top = 375
      Width = 13
      Height = 27
      Caption = '2'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label11: TLabel
      Left = 3
      Top = 315
      Width = 13
      Height = 27
      Caption = '3'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label12: TLabel
      Left = 3
      Top = 255
      Width = 13
      Height = 27
      Caption = '4'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label13: TLabel
      Left = 3
      Top = 195
      Width = 13
      Height = 27
      Caption = '5'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label14: TLabel
      Left = 3
      Top = 135
      Width = 13
      Height = 27
      Caption = '6'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label15: TLabel
      Left = 3
      Top = 75
      Width = 13
      Height = 27
      Caption = '7'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
    object Label16: TLabel
      Left = 3
      Top = 15
      Width = 13
      Height = 27
      Caption = '8'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
    end
  end
  object RightPanel: TPanel
    Left = 504
    Top = 0
    Width = 230
    Height = 511
    Align = alClient
    TabOrder = 1
    object White: TLabel
      Left = 66
      Top = 488
      Width = 153
      Height = 17
      AutoSize = False
      Caption = 'White'
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Black: TLabel
      Left = 66
      Top = 8
      Width = 153
      Height = 17
      AutoSize = False
      Caption = 'Black'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object StringGrid1: TStringGrid
      Left = 66
      Top = 33
      Width = 153
      Height = 162
      BiDiMode = bdLeftToRight
      BorderStyle = bsNone
      ColCount = 3
      DefaultColWidth = 50
      DefaultRowHeight = 17
      FixedCols = 0
      RowCount = 9
      ParentBiDiMode = False
      ScrollBars = ssNone
      TabOrder = 2
      OnDrawCell = StringGrid1DrawCell
      OnMouseDown = StringGrid1MouseDown
      ColWidths = (
        33
        50
        50)
    end
    object Edit1: TEdit
      Left = 66
      Top = 456
      Width = 153
      Height = 23
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnKeyPress = Edit1KeyPress
    end
    object Memo1: TMemo
      Left = 66
      Top = 200
      Width = 153
      Height = 257
      Font.Charset = TURKISH_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
      ScrollBars = ssVertical
      TabOrder = 1
    end
    object Button3: TButton
      Left = 12
      Top = 242
      Width = 41
      Height = 25
      Caption = 'Menu'
      TabOrder = 4
      OnClick = Button3Click
    end
    object ScrollBar1: TScrollBar
      Left = 202
      Top = 33
      Width = 17
      Height = 162
      Kind = sbVertical
      LargeChange = 6
      Max = 0
      PageSize = 0
      TabOrder = 3
      OnScroll = ScrollBar1Scroll
    end
    object Panel1: TPanel
      Left = 12
      Top = 8
      Width = 41
      Height = 41
      TabOrder = 5
      object BlackP: TImage
        Left = 0
        Top = 0
        Width = 41
        Height = 41
        Stretch = True
        Transparent = True
        Visible = False
      end
      object bp: TLabel
        Left = 0
        Top = 17
        Width = 12
        Height = 24
        Caption = '0'
        Color = clCaptionText
        Font.Charset = TURKISH_CHARSET
        Font.Color = clWindow
        Font.Height = -21
        Font.Name = 'Arial'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        Visible = False
      end
    end
    object Panel2: TPanel
      Left = 12
      Top = 50
      Width = 41
      Height = 41
      TabOrder = 6
      object BlackN: TImage
        Left = 0
        Top = 0
        Width = 41
        Height = 41
        Stretch = True
        Transparent = True
        Visible = False
      end
      object bn: TLabel
        Left = 0
        Top = 17
        Width = 12
        Height = 24
        Caption = '0'
        Color = clCaptionText
        Font.Charset = TURKISH_CHARSET
        Font.Color = clWindow
        Font.Height = -21
        Font.Name = 'Arial'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        Visible = False
      end
    end
    object Panel3: TPanel
      Left = 12
      Top = 92
      Width = 41
      Height = 41
      TabOrder = 7
      object BlackB: TImage
        Left = 0
        Top = 0
        Width = 41
        Height = 41
        Stretch = True
        Transparent = True
        Visible = False
      end
      object bb: TLabel
        Left = 0
        Top = 17
        Width = 12
        Height = 24
        Caption = '0'
        Color = clCaptionText
        Font.Charset = TURKISH_CHARSET
        Font.Color = clWindow
        Font.Height = -21
        Font.Name = 'Arial'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        Visible = False
      end
    end
    object Panel4: TPanel
      Left = 12
      Top = 134
      Width = 41
      Height = 41
      TabOrder = 8
      object BlackR: TImage
        Left = 0
        Top = 0
        Width = 41
        Height = 41
        Stretch = True
        Transparent = True
        Visible = False
      end
      object br: TLabel
        Left = 0
        Top = 17
        Width = 12
        Height = 24
        Caption = '0'
        Color = clCaptionText
        Font.Charset = TURKISH_CHARSET
        Font.Color = clWindow
        Font.Height = -21
        Font.Name = 'Arial'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        Visible = False
      end
    end
    object Panel5: TPanel
      Left = 12
      Top = 176
      Width = 41
      Height = 41
      TabOrder = 9
      object BlackQ: TImage
        Left = 0
        Top = 0
        Width = 41
        Height = 41
        Stretch = True
        Transparent = True
        Visible = False
      end
      object bq: TLabel
        Left = 0
        Top = 17
        Width = 12
        Height = 24
        Caption = '0'
        Color = clCaptionText
        Font.Charset = TURKISH_CHARSET
        Font.Color = clWindow
        Font.Height = -21
        Font.Name = 'Arial'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        Visible = False
      end
    end
    object Panel6: TPanel
      Left = 12
      Top = 293
      Width = 41
      Height = 41
      TabOrder = 10
      object WhiteQ: TImage
        Left = 0
        Top = 0
        Width = 41
        Height = 41
        Stretch = True
        Transparent = True
        Visible = False
      end
      object wq: TLabel
        Left = 0
        Top = 17
        Width = 12
        Height = 24
        Caption = '0'
        Color = clCaptionText
        Font.Charset = TURKISH_CHARSET
        Font.Color = clWindow
        Font.Height = -21
        Font.Name = 'Arial'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        Visible = False
      end
    end
    object Panel7: TPanel
      Left = 12
      Top = 335
      Width = 41
      Height = 41
      TabOrder = 11
      object WhiteR: TImage
        Left = 0
        Top = 0
        Width = 41
        Height = 41
        Stretch = True
        Transparent = True
        Visible = False
      end
      object wr: TLabel
        Left = 0
        Top = 17
        Width = 12
        Height = 24
        Caption = '0'
        Color = clCaptionText
        Font.Charset = TURKISH_CHARSET
        Font.Color = clWindow
        Font.Height = -21
        Font.Name = 'Arial'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        Visible = False
      end
    end
    object Panel8: TPanel
      Left = 12
      Top = 377
      Width = 41
      Height = 41
      TabOrder = 12
      object WhiteB: TImage
        Left = 0
        Top = 0
        Width = 41
        Height = 41
        Stretch = True
        Transparent = True
        Visible = False
      end
      object wb: TLabel
        Left = 0
        Top = 17
        Width = 12
        Height = 24
        Caption = '0'
        Color = clCaptionText
        Font.Charset = TURKISH_CHARSET
        Font.Color = clWindow
        Font.Height = -21
        Font.Name = 'Arial'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        Visible = False
      end
    end
    object Panel9: TPanel
      Left = 12
      Top = 419
      Width = 41
      Height = 41
      TabOrder = 13
      object WhiteN: TImage
        Left = 0
        Top = 0
        Width = 41
        Height = 41
        Stretch = True
        Transparent = True
        Visible = False
      end
      object wn: TLabel
        Left = 0
        Top = 17
        Width = 12
        Height = 24
        Caption = '0'
        Color = clCaptionText
        Font.Charset = TURKISH_CHARSET
        Font.Color = clWindow
        Font.Height = -21
        Font.Name = 'Arial'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        Visible = False
      end
    end
    object Panel10: TPanel
      Left = 12
      Top = 461
      Width = 41
      Height = 41
      TabOrder = 14
      object WhiteP: TImage
        Left = 0
        Top = 0
        Width = 41
        Height = 41
        Stretch = True
        Transparent = True
        Visible = False
      end
      object wp: TLabel
        Left = 0
        Top = 17
        Width = 12
        Height = 24
        Caption = '0'
        Color = clCaptionText
        Font.Charset = TURKISH_CHARSET
        Font.Color = clWindow
        Font.Height = -21
        Font.Name = 'Arial'
        Font.Style = []
        ParentColor = False
        ParentFont = False
        Visible = False
      end
    end
  end
  object BottomPanel: TPanel
    Left = 0
    Top = 511
    Width = 734
    Height = 96
    Align = alBottom
    TabOrder = 2
    object CppWebBrowser1: TCppWebBrowser
      Left = 1
      Top = 1
      Width = 732
      Height = 94
      Align = alClient
      TabOrder = 0
      ControlData = {
        4C000000A84B0000B70900000000000000000000000000000000000000000000
        000000004C000000000000000000000001000000E0D057007335CF11AE690800
        2B2E126208000000000000004C0000000114020000000000C000000000000046
        8000000000000000000000000000000000000000000000000000000000000000
        00000000000000000100000000000000000000000000000000000000}
    end
  end
  object ImageList1: TImageList
    Height = 60
    Width = 60
    Left = 640
    Top = 240
  end
  object ImageList2: TImageList
    Height = 60
    Width = 60
    Left = 672
    Top = 240
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 608
    Top = 240
  end
  object PopupAction: TPopupMenu
    Left = 576
    Top = 240
    object FlipBoard1: TMenuItem
      Caption = 'Flip Board'
      OnClick = FlipBoard1Click
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object Engine1: TMenuItem
      Caption = 'Engine'
      object Compute1: TMenuItem
        Caption = 'Compute'
        OnClick = Compute1Click
      end
      object Speed1: TMenuItem
        Caption = 'Speed'
        object Fast1: TMenuItem
          Caption = 'Fast'
          Checked = True
          OnClick = Fast1Click
        end
        object Medium1: TMenuItem
          Caption = 'Medium'
          OnClick = Medium1Click
        end
        object Slow1: TMenuItem
          Caption = 'Slow'
          OnClick = Slow1Click
        end
      end
    end
  end
  object PopupBoard: TPopupMenu
    Left = 8
    Top = 480
    object InvertBoard1: TMenuItem
      Caption = 'Invert Board'
      OnClick = InvertBoard1Click
    end
  end
end
