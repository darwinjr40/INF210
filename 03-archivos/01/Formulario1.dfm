object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 372
  ClientWidth = 735
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Edit1: TEdit
    Left = 160
    Top = 80
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
  end
  object ButtonGroup1: TButtonGroup
    Left = 0
    Top = 0
    Width = 129
    Height = 369
    ButtonHeight = 30
    ButtonWidth = 150
    Items = <
      item
        Caption = 'Contar Vocales'
        OnClick = Button1Click
      end
      item
      end
      item
      end
      item
      end>
    TabOrder = 1
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 192
  end
end
