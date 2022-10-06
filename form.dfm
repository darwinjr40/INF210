object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 518
  ClientWidth = 932
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Edit1: TEdit
    Left = 176
    Top = 64
    Width = 513
    Height = 26
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 176
    Top = 96
    Width = 513
    Height = 26
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 176
    Top = 136
    Width = 513
    Height = 26
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
  end
  object StringGrid1: TStringGrid
    Left = 40
    Top = 200
    Width = 785
    Height = 233
    DrawingStyle = gdsClassic
    FixedCols = 0
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    ParentFont = False
    TabOrder = 3
  end
  object Button1: TButton
    Left = 40
    Top = 66
    Width = 113
    Height = 24
    Caption = 'dimensionarVector'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 40
    Top = 96
    Width = 113
    Height = 25
    Caption = 'dimensionar matriz'
    TabOrder = 5
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 64
    Top = 160
    Width = 75
    Height = 25
    Caption = 'limpiar Matriz'
    TabOrder = 6
    OnClick = Button3Click
  end
  object Edit4: TEdit
    Left = 176
    Top = 168
    Width = 513
    Height = 26
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 8
    object cadenas1: TMenuItem
      Caption = 'cadena'
      object prueba1: TMenuItem
        Caption = 'prueba'
        OnClick = prueba1Click
      end
      object PRIMERNumero1: TMenuItem
        Caption = 'PRIMER Numero'
        OnClick = PRIMERNumero1Click
      end
      object Numeromayor1: TMenuItem
        Caption = 'Numero mayor'
        OnClick = Numeromayor1Click
      end
      object Vector1: TMenuItem
        Caption = 'Vector'
      end
      object eliminarelementosdeunapos1: TMenuItem
        Caption = 'eliminar elementos de una pos '
      end
      object eliminarprimernumero1: TMenuItem
        Caption = 'eliminar primer numero'
        OnClick = eliminarprimernumero1Click
      end
      object Deliminarprimercaracterdecadapalabra1: TMenuItem
        Caption = 'D-eliminar primer caracter de cada palabra'
        OnClick = Deliminarprimercaracterdecadapalabra1Click
      end
      object N20192A1: TMenuItem
        Caption = '2019-2A'
        OnClick = N20192A1Click
      end
    end
    object Dunnia1: TMenuItem
      Caption = 'M-Dunnia'
      object eliminarprimeraletradecadapalabra1: TMenuItem
        Caption = '2022-1-eliminar primera letra de cada palabra    '
        OnClick = eliminarprimeraletradecadapalabra1Click
      end
      object N202021: TMenuItem
        Caption = '2020_2 && 2021_1R'
        OnClick = N202021Click
      end
      object N202111: TMenuItem
        Caption = '2021_1'
        OnClick = N202111Click
      end
      object N202112: TMenuItem
        Caption = '2021_1'
        OnClick = N202112Click
      end
      object N202211: TMenuItem
        Caption = '2022-1'
        OnClick = N202211Click
      end
    end
    object matriz1: TMenuItem
      Caption = 'M-Contreras'
      object cargarenformavector1: TMenuItem
        Caption = 'cargar en forma vector'
        OnClick = cargarenformavector1Click
      end
      object Magico1: TMenuItem
        Caption = 'Magico impar'
        OnClick = Magico1Click
      end
      object cargarbordes1: TMenuItem
        Caption = 'cargar dentro hacia fuera'
        OnClick = cargarbordes1Click
      end
      object N201921: TMenuItem
        Caption = '2019_2B'
        OnClick = N201921Click
      end
      object N201931: TMenuItem
        Caption = '2019_32'
        OnClick = N201931Click
      end
      object N20201segundaescala1: TMenuItem
        Caption = '2020-1 segunda escala'
        OnClick = N20201segundaescala1Click
      end
      object N202011: TMenuItem
        Caption = '2020-2'
        OnClick = N202011Click
      end
      object N202113: TMenuItem
        Caption = '2021-1'
        OnClick = N202113Click
      end
      object N202121: TMenuItem
        Caption = '2021-2'
        OnClick = N202121Click
      end
      object N20213202211: TMenuItem
        Caption = '2021-3 ^ 2022-1'
        OnClick = N20213202211Click
      end
      object N20221B1: TMenuItem
        Caption = '2022-1B'
        OnClick = N20221B1Click
      end
      object caracol1: TMenuItem
        Caption = 'caracol'
        OnClick = caracol1Click
      end
    end
    object Vector2: TMenuItem
      Caption = 'vector'
      object Insertarunelementoordenado1: TMenuItem
        Caption = 'Insertar un elemento ordenado Desc'
        OnClick = Insertarunelementoordenado1Click
      end
      object EliminarPrimerosElementos1: TMenuItem
        Caption = 'Eliminar Primeros Elementos'
        OnClick = EliminarPrimerosElementos1Click
      end
      object generarnumeroconunvector1: TMenuItem
        Caption = 'generar numero con un vector'
        OnClick = generarnumeroconunvector1Click
      end
    end
  end
end
