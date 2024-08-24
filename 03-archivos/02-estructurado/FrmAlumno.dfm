object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 560
  ClientWidth = 913
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 246
    Top = 25
    Width = 33
    Height = 13
    Caption = 'Codigo'
  end
  object Label2: TLabel
    Left = 246
    Top = 52
    Width = 37
    Height = 13
    Caption = 'Nombre'
  end
  object Label3: TLabel
    Left = 246
    Top = 84
    Width = 43
    Height = 13
    Caption = 'Direccion'
  end
  object Label4: TLabel
    Left = 246
    Top = 115
    Width = 29
    Height = 13
    Caption = 'Fecha'
  end
  object Edit1: TEdit
    Left = 318
    Top = 27
    Width = 121
    Height = 21
    TabOrder = 0
    OnExit = Edit1Exit
  end
  object Edit2: TEdit
    Left = 318
    Top = 54
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 318
    Top = 81
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object MaskEdit1: TMaskEdit
    Left = 318
    Top = 108
    Width = 121
    Height = 21
    EditMask = '!99/99/0000;1;_'
    MaxLength = 10
    TabOrder = 3
    Text = '  /  /    '
  end
  object Button1: TButton
    Left = 315
    Top = 143
    Width = 59
    Height = 25
    Caption = 'Guardar'
    TabOrder = 4
    OnClick = GuardarClick
  end
  object Button2: TButton
    Left = 380
    Top = 143
    Width = 59
    Height = 25
    Caption = 'Eliminar'
    TabOrder = 5
    OnClick = EliminarClick
  end
  object Button4: TButton
    Left = 646
    Top = 8
    Width = 75
    Height = 25
    Caption = 'actualizar'
    TabOrder = 6
    OnClick = actualizarClick
  end
  object Button5: TButton
    Left = 646
    Top = 39
    Width = 75
    Height = 25
    Caption = 'actualizarv2'
    TabOrder = 7
    OnClick = actualizarv2Click
  end
  object Button6: TButton
    Left = 743
    Top = 8
    Width = 143
    Height = 25
    Caption = 'expandir-new-file'
    TabOrder = 8
    OnClick = expandirClick
  end
  object Button7: TButton
    Left = 646
    Top = 70
    Width = 75
    Height = 25
    Caption = 'actualizarv3'
    TabOrder = 9
    OnClick = actualizarv3
  end
  object Button8: TButton
    Left = 646
    Top = 101
    Width = 75
    Height = 25
    Caption = 'actualizarv4'
    TabOrder = 10
    OnClick = actualizarv4Click
  end
  object Button9: TButton
    Left = 746
    Top = 189
    Width = 143
    Height = 25
    Caption = 'prueba'
    TabOrder = 11
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 743
    Top = 39
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
    Left = 199
    Top = 246
    Width = 602
    Height = 262
    DefaultColWidth = 100
    DrawingStyle = gdsClassic
    FixedCols = 0
    TabOrder = 14
  end
  object mostrar: TButton
    Left = 199
    Top = 207
    Width = 59
    Height = 25
    Caption = 'mostrar'
    TabOrder = 15
    OnClick = mostrarClick
  end
  object ButtonGroup1: TButtonGroup
    Left = 8
    Top = 8
    Width = 185
    Height = 529
    ButtonHeight = 32
    ButtonWidth = 200
    Items = <
      item
        Caption = 'cargar datos locales'
        OnClick = onClickLoad
      end
      item
        Caption = 'expandir-file'
        OnClick = expandirFileClick
      end
      item
        Caption = 'Crear txt por codigo indexado'
        OnClick = createCodigoClick
      end
      item
        Caption = 'Crear txt de un mes determinado'
        OnClick = onClickCreateMonthFile
      end
      item
        Caption = 'obtener codigo: busqueda por nombre'
        OnClick = onClickSearchName
      end
      item
        Caption = 'proceso: mostrar el alumno menor por index'
        OnClick = searchMenByIndex
      end
      item
        Caption = 'busqueda binaria index por codigo'
        OnClick = searchBinaryCodeByIndex
      end
      item
      end>
    TabOrder = 16
  end
  object ButtonNavIdxIni: TButton
    Left = 465
    Top = 22
    Width = 81
    Height = 25
    Caption = 'NavegarIdx'
    TabOrder = 17
    OnClick = ButtonNavIdxIniClick
  end
  object ButtonNavIdxSig: TButton
    Left = 506
    Top = 53
    Width = 40
    Height = 25
    Caption = '>>'
    Enabled = False
    TabOrder = 18
    OnClick = ButtonNavIdxSigClick
  end
  object ButtonNavIdxAnt: TButton
    Left = 465
    Top = 53
    Width = 40
    Height = 25
    Caption = '<<'
    Enabled = False
    TabOrder = 19
    OnClick = ButtonNavIdxAntClick
  end
  object ButtonNavIdxFin: TButton
    Left = 464
    Top = 84
    Width = 82
    Height = 25
    Caption = 'FinNavegarIdx'
    Enabled = False
    TabOrder = 20
    OnClick = ButtonNavIdxFinClick
  end
  object Button13: TButton
    Left = 367
    Top = 207
    Width = 75
    Height = 25
    Caption = 'pregunta2'
    TabOrder = 21
    OnClick = pregunta2
  end
  object ComboBoxCreateIdx: TComboBox
    Left = 464
    Top = 115
    Width = 121
    Height = 21
    Style = csDropDownList
    ItemIndex = 0
    TabOrder = 22
    Text = 'Seleccione Crear idx'
    OnChange = ComboBoxCreateIdxChange
    Items.Strings = (
      'Seleccione Crear idx'
      'codigo'
      'nombre'
      'direccion'
      'fecha'
      'telefono')
  end
  object ComboBoxOrdenarIdx: TComboBox
    Left = 464
    Top = 142
    Width = 140
    Height = 21
    Style = csDropDownList
    ItemIndex = 0
    TabOrder = 23
    Text = 'Seleccione Ordenar Idx'
    OnChange = ComboBoxOrdenarIdxChange
    Items.Strings = (
      'Seleccione Ordenar Idx'
      'codigo'
      'nombre'
      'direccion'
      'fecha'
      'telefono')
  end
  object ComboBoxExportIdx: TComboBox
    Left = 464
    Top = 169
    Width = 145
    Height = 21
    Style = csDropDownList
    TabOrder = 24
    OnChange = ComboBoxExportIdxChange
    Items.Strings = (
      'Seleccione exportar Idx'
      'codigo'
      'nombre'
      'direccion'
      'fecha'
      'telefono')
  end
  object Button3: TButton
    Left = 286
    Top = 207
    Width = 75
    Height = 25
    Caption = 'pregunta1'
    TabOrder = 25
    OnClick = Button3Click
  end
end
