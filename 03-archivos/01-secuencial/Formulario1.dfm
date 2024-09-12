object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 490
  ClientWidth = 755
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
    Left = 312
    Top = 88
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object ButtonGroup1: TButtonGroup
    Left = 0
    Top = 0
    Width = 161
    Height = 482
    ButtonHeight = 30
    ButtonWidth = 150
    Items = <
      item
        Caption = 'Contar Vocales'
        OnClick = ButtonSelectClick
      end
      item
        Caption = 'LimpiarVocSig'
        OnClick = LimpiarVocSigClick
      end
      item
        Caption = '2022-2-#1-crearNivel21'
        OnClick = crearNivel21Form
      end
      item
        Caption = '2023-2-#2-VerificarNivel21'
        OnClick = VerificarNivel21Click
      end
      item
        Caption = '2023-1-#1-searchAndreplace'
        OnClick = onSearchAndReplace
      end
      item
        Caption = '2023-2-#1-CreateNumbersByLine'
        OnClick = pruebaClick
      end
      item
        Caption = '2023-2-#2-createFirtPal'
        OnClick = CreateFirstWord
      end>
    TabOrder = 1
  end
  object Edit2: TEdit
    Left = 312
    Top = 115
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object Button1: TButton
    Left = 192
    Top = 86
    Width = 75
    Height = 25
    Caption = 'Mostrar txt'
    TabOrder = 3
    OnClick = Button1Click
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 176
    Top = 8
  end
end
