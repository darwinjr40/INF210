object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 540
  ClientWidth = 913
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 190
    Top = 31
    Width = 33
    Height = 13
    Caption = 'Codigo'
  end
  object Label2: TLabel
    Left = 190
    Top = 58
    Width = 37
    Height = 13
    Caption = 'Nombre'
  end
  object Label3: TLabel
    Left = 190
    Top = 90
    Width = 43
    Height = 13
    Caption = 'Direccion'
  end
  object Label4: TLabel
    Left = 190
    Top = 121
    Width = 29
    Height = 13
    Caption = 'Fecha'
  end
  object Edit1: TEdit
    Left = 262
    Top = 33
    Width = 121
    Height = 21
    TabOrder = 0
    OnExit = Edit1Exit
  end
  object Edit2: TEdit
    Left = 262
    Top = 60
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 262
    Top = 87
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object MaskEdit1: TMaskEdit
    Left = 262
    Top = 114
    Width = 121
    Height = 21
    EditMask = '!99/99/0000;1;_'
    MaxLength = 10
    TabOrder = 3
    Text = '  /  /    '
  end
  object Button1: TButton
    Left = 176
    Top = 148
    Width = 75
    Height = 25
    Caption = 'Cargar'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 262
    Top = 148
    Width = 75
    Height = 25
    Caption = 'Eliminar'
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button4: TButton
    Left = 577
    Top = 22
    Width = 75
    Height = 25
    Caption = 'actualizar'
    TabOrder = 6
    OnClick = actualizarClick
  end
  object Button5: TButton
    Left = 577
    Top = 53
    Width = 75
    Height = 25
    Caption = 'actualizarv2'
    TabOrder = 7
    OnClick = actualizarv2Click
  end
  object Button6: TButton
    Left = 674
    Top = 22
    Width = 143
    Height = 25
    Caption = 'expandir-new-file'
    TabOrder = 8
    OnClick = expandirClick
  end
  object Button7: TButton
    Left = 577
    Top = 84
    Width = 75
    Height = 25
    Caption = 'actualizarv3'
    TabOrder = 9
    OnClick = actualizarv3
  end
  object Button8: TButton
    Left = 577
    Top = 115
    Width = 75
    Height = 25
    Caption = 'actualizarv4'
    TabOrder = 10
    OnClick = actualizarv4Click
  end
  object Button9: TButton
    Left = 746
    Top = 127
    Width = 143
    Height = 25
    Caption = 'prueba'
    TabOrder = 11
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 674
    Top = 53
    Width = 143
    Height = 25
    Caption = 'showExpandir'
    TabOrder = 12
    OnClick = showExpandirClick
  end
  object Button11: TButton
    Left = 746
    Top = 158
    Width = 143
    Height = 25
    Caption = 'prueba-constructor-copia'
    TabOrder = 13
    OnClick = Button11Click
  end
  object StringGrid1: TStringGrid
    Left = 176
    Top = 195
    Width = 531
    Height = 262
    DefaultColWidth = 100
    DrawingStyle = gdsClassic
    FixedCols = 0
    TabOrder = 14
  end
  object mostrar: TButton
    Left = 358
    Top = 148
    Width = 75
    Height = 25
    Caption = 'mostrar'
    TabOrder = 15
    OnClick = mostrarClick
  end
  object ButtonGroup1: TButtonGroup
    Left = 8
    Top = 148
    Width = 129
    Height = 293
    ButtonHeight = 32
    ButtonWidth = 130
    Items = <
      item
        Caption = 'expandir-file'
        OnClick = expandirFileClick
      end
      item
      end>
    TabOrder = 16
  end
  object ButtonNavIdx: TButton
    Left = 432
    Top = 47
    Width = 75
    Height = 25
    Caption = 'NavegarIdx'
    TabOrder = 17
    OnClick = ButtonNavIdxClick
  end
  object ButtonNavIdxSig: TButton
    Left = 480
    Top = 78
    Width = 27
    Height = 25
    Caption = '>>'
    Enabled = False
    TabOrder = 18
    OnClick = ButtonNavIdxSigClick
  end
  object ButtonNavIdxAnt: TButton
    Left = 432
    Top = 78
    Width = 25
    Height = 25
    Caption = '<<'
    Enabled = False
    TabOrder = 19
    OnClick = ButtonNavIdxAntClick
  end
  object ButtonFinNavIdx: TButton
    Left = 432
    Top = 109
    Width = 75
    Height = 25
    Caption = 'FinNavegarIdx'
    TabOrder = 20
    OnClick = ButtonFinNavIdxClick
  end
  object ComboBox1: TComboBox
    Left = 432
    Top = 20
    Width = 81
    Height = 21
    Style = csDropDownList
    DragCursor = crDefault
    ItemIndex = 0
    TabOrder = 21
    Text = 'Codigo'
    Items.Strings = (
      'Codigo'
      'Nombre'
      'Direccion'
      'Fecha')
  end
  object MainMenu1: TMainMenu
    Left = 8
    Top = 8
    object indices1: TMenuItem
      Caption = 'Indices'
      object codgio1: TMenuItem
        Caption = 'codigo'
        OnClick = codgio1Click
      end
    end
    object Ordenar1: TMenuItem
      Caption = 'Ordenar'
      object codigo1: TMenuItem
        Caption = 'codigo'
        OnClick = codigo1Click
      end
    end
  end
end
