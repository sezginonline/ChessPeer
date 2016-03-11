object PromotionForm: TPromotionForm
  Left = 384
  Top = 389
  BorderStyle = bsDialog
  Caption = 'Please select the piece:'
  ClientHeight = 41
  ClientWidth = 332
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Queen'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 88
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Rook'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 168
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Bishop'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 248
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Knight'
    TabOrder = 3
    OnClick = Button4Click
  end
end
