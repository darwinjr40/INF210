object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 217
  ClientWidth = 560
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
  object Label1: TLabel
    Left = 104
    Top = 43
    Width = 33
    Height = 13
    Caption = 'Codigo'
  end
  object Label2: TLabel
    Left = 104
    Top = 70
    Width = 37
    Height = 13
    Caption = 'Nombre'
  end
  object Label3: TLabel
    Left = 104
    Top = 102
    Width = 43
    Height = 13
    Caption = 'Direccion'
  end
  object Label4: TLabel
    Left = 104
    Top = 133
    Width = 29
    Height = 13
    Caption = 'Fecha'
  end
  object Edit1: TEdit
    Left = 176
    Top = 40
    Width = 121
    Height = 21
    TabOrder = 0
    OnExit = Edit1Exit
  end
  object Edit2: TEdit
    Left = 176
    Top = 72
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 176
    Top = 99
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object MaskEdit1: TMaskEdit
    Left = 176
    Top = 126
    Width = 121
    Height = 21
    EditMask = '!99/99/0000;1;_'
    MaxLength = 10
    TabOrder = 3
    Text = '  /  /    '
  end
  object Button1: TButton
    Left = 156
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Cargar'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 254
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Eliminar'
    TabOrder = 5
  end
  object Button3: TButton
    Left = 360
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Limpiar'
    TabOrder = 6
  end
  object Button4: TButton
    Left = 384
    Top = 40
    Width = 75
    Height = 25
    Caption = 'actualizar'
    TabOrder = 7
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 384
    Top = 71
    Width = 75
    Height = 25
    Caption = 'actualizarv2'
    TabOrder = 8
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 384
    Top = 102
    Width = 75
    Height = 25
    Caption = 'expandir'
    TabOrder = 9
    OnClick = Button6Click
  end
end
