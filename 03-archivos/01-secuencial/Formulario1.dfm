object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 386
  ClientWidth = 532
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
    Left = 152
    Top = 104
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
        Caption = 'Select File'
        OnClick = SelectClick
      end
      item
        Caption = 'Contar Vocales'
        OnClick = ButtonSelectClick
      end
      item
        Caption = 'LimpiarVocSig'
        OnClick = LimpiarVocSigClick
      end
      item
      end>
    TabOrder = 1
  end
  object ComboBox1: TComboBox
    Left = 152
    Top = 56
    Width = 145
    Height = 21
    ItemIndex = 0
    TabOrder = 2
    Text = 'File1'
    Items.Strings = (
      'File1'
      'File2')
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 192
  end
end
