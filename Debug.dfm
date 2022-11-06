object DebugForm: TDebugForm
  Left = 336
  Top = 210
  Width = 362
  Height = 355
  Caption = 'DebugForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 144
    Top = 96
    Width = 51
    Height = 16
    Caption = #1052#1080#1085#1091#1090#1099
  end
  object Label2: TLabel
    Left = 168
    Top = 120
    Width = 33
    Height = 16
    Caption = #1063#1072#1089#1099
  end
  object wait1: TCSpinEdit
    Left = 208
    Top = 96
    Width = 65
    Height = 26
    TabOrder = 0
  end
  object Button1: TButton
    Left = 272
    Top = 120
    Width = 57
    Height = 25
    Caption = #1046#1076#1072#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object Chours: TCSpinEdit
    Left = 208
    Top = 120
    Width = 65
    Height = 26
    TabOrder = 2
  end
  object BitBtn1: TBitBtn
    Left = 24
    Top = 88
    Width = 75
    Height = 25
    Caption = 'BitBtn1'
    TabOrder = 3
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 24
    Top = 120
    Width = 75
    Height = 25
    TabOrder = 4
    Kind = bkAbort
  end
  object Table: TStringGrid
    Left = 16
    Top = 152
    Width = 225
    Height = 161
    ColCount = 7
    DefaultColWidth = 28
    FixedCols = 0
    RowCount = 6
    FixedRows = 0
    TabOrder = 5
  end
  object CSpinEdit1: TCSpinEdit
    Left = 8
    Top = 8
    Width = 65
    Height = 26
    TabOrder = 6
  end
end
