object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 521
  ClientWidth = 931
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 931
    Height = 521
    ActivePage = TabSheet3
    Align = alClient
    TabOrder = 0
    ExplicitHeight = 674
    object TabSheet1: TTabSheet
      Caption = 'numero'
      ExplicitTop = 32
      ExplicitWidth = 209
      ExplicitHeight = 86
    end
    object TabSheet2: TTabSheet
      Caption = 'cadena'
      ImageIndex = 1
      ExplicitTop = 32
      ExplicitWidth = 169
      ExplicitHeight = 86
    end
    object TabSheet3: TTabSheet
      Caption = 'vector'
      ImageIndex = 2
      ExplicitLeft = 8
      ExplicitTop = 28
      object Button1: TButton
        Left = 184
        Top = 51
        Width = 113
        Height = 24
        Caption = 'dimensionarVector'
        TabOrder = 0
        OnClick = Button1Click
      end
      object Edit3: TEdit
        Left = 584
        Top = 88
        Width = 100
        Height = 26
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
      end
      object Edit4: TEdit
        Left = 584
        Top = 120
        Width = 100
        Height = 26
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object ButtonGroup1: TButtonGroup
        Left = 0
        Top = 0
        Width = 137
        Height = 417
        Items = <>
        TabOrder = 3
      end
      object StringGridVector1: TStringGrid
        Left = 184
        Top = 152
        Width = 437
        Height = 33
        DefaultColWidth = 50
        DrawingStyle = gdsClassic
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
        ParentFont = False
        TabOrder = 4
        OnDrawCell = DrawCell
      end
      object Edit5: TEdit
        Left = 320
        Top = 48
        Width = 153
        Height = 26
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        TextHint = 'cant de elementos'
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'matriz'
      ImageIndex = 3
      ExplicitLeft = 8
      ExplicitTop = 28
      object Button2: TButton
        Left = 19
        Top = 88
        Width = 113
        Height = 25
        Caption = 'dimensionar matriz'
        TabOrder = 0
        OnClick = Button2Click
      end
      object Button3: TButton
        Left = 138
        Top = 88
        Width = 75
        Height = 25
        Caption = 'limpiar Matriz'
        TabOrder = 1
        OnClick = Button3Click
      end
      object Edit1: TEdit
        Left = 19
        Top = 56
        Width = 100
        Height = 26
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        TextHint = 'filas'
      end
      object Edit2: TEdit
        Left = 138
        Top = 56
        Width = 100
        Height = 26
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        TextHint = 'columnas'
      end
      object StringGrid1: TStringGrid
        Left = 19
        Top = 248
        Width = 400
        Height = 169
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
        TabOrder = 4
      end
      object StringGrid2: TStringGrid
        Left = 464
        Top = 248
        Width = 437
        Height = 169
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
        TabOrder = 5
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 384
    object Numero1: TMenuItem
      Caption = 'numero'
      Checked = True
      object numeroesprimo1: TMenuItem
        Caption = 'numero es primo'
        OnClick = numeroesprimo1Click
      end
      object getmaymen1: TMenuItem
        Caption = 'get: may-men'
        OnClick = getmaymen1Click
      end
      object N20231NesimTerm1: TMenuItem
        Caption = 'dunnia-2023-1-Nesim-Term'
        OnClick = N20231NesimTerm1Click
      end
    end
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
      object eliminarprimeraletradecadapalabra1: TMenuItem
        Caption = 'dunnia-2022-1-eliminar primera letra de cada palabra    '
        OnClick = eliminarprimeraletradecadapalabra1Click
      end
      object prueba2: TMenuItem
        Caption = 'dunnia-obtener cantidad de conjunto de caracteres'
        OnClick = prueba2Click
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
      object N20222Acargarvectorconlosdigitosdeunnumero1: TMenuItem
        Caption = '2022-2A-cargar vector con los digitos de un numero'
        OnClick = N20222Acargarvectorconlosdigitosdeunnumero1Click
      end
      object N20223cargarVectorConSerieFibonacci1: TMenuItem
        Caption = '2022-3-cargarVectorConSerieFibonacci'
        OnClick = N20223cargarVectorConSerieFibonacci1Click
      end
      object cargarVectorConPalabras1: TMenuItem
        Caption = 'cargarVectorConPalabras'
        OnClick = cargarVectorConPalabras1Click
      end
      object cargarDigitosrep1: TMenuItem
        Caption = 'cargarDigitosrep'
        OnClick = cargarDigitosrep1Click
      end
      object cargar1: TMenuItem
        Caption = 'cargar2letrasPalabra'
        OnClick = cargar1Click
      end
      object promedioXElem1: TMenuItem
        Caption = 'promedioXElem'
        OnClick = promedioXElem1Click
      end
      object cargarDigRepDesc202311: TMenuItem
        Caption = 'cargarDigRepDesc_2023-1'
        OnClick = cargarDigRepDesc202311Click
      end
      object vectorinterseccion1: TMenuItem
        Caption = 'dunnia-vector-interseccion'
        OnClick = vectorinterseccion1Click
      end
      object prueba3: TMenuItem
        Caption = 'dunnia-examen2022-2-vector'
        OnClick = prueba3Click
      end
      object invertir1: TMenuItem
        Caption = 'shirley-invertir'
        OnClick = invertir1Click
      end
      object serie1: TMenuItem
        Caption = 'shirley-serie'
        OnClick = serie1Click
      end
    end
    object matriz1: TMenuItem
      Caption = 'matriz'
      object cargarenformavector1: TMenuItem
        Caption = 'contreras-cargar en forma vector'
        OnClick = cargarenformavector1Click
      end
      object Magico1: TMenuItem
        Caption = 'contreras-Magico impar'
        OnClick = Magico1Click
      end
      object cargarbordes1: TMenuItem
        Caption = 'contreras-cargar dentro hacia fuera'
        OnClick = cargarbordes1Click
      end
      object N201921: TMenuItem
        Caption = 'contreras-2019_2B'
        OnClick = N201921Click
      end
      object N201931: TMenuItem
        Caption = 'contreras-2019_32'
        OnClick = N201931Click
      end
      object N20201segundaescala1: TMenuItem
        Caption = 'contreras-2020-1 segunda escala'
        OnClick = N20201segundaescala1Click
      end
      object N202011: TMenuItem
        Caption = 'contreras-2020-2'
        OnClick = N202011Click
      end
      object N202113: TMenuItem
        Caption = 'contreras-2021-1'
        OnClick = N202113Click
      end
      object N202121: TMenuItem
        Caption = 'contreras-2021-2'
        OnClick = N202121Click
      end
      object N20213202211: TMenuItem
        Caption = 'contreras-2021-3 ^ 2022-1'
        OnClick = N20213202211Click
      end
      object N20221B1: TMenuItem
        Caption = 'contreras-2022-1B'
        OnClick = N20221B1Click
      end
      object caracol1: TMenuItem
        Caption = 'contreras-caracol'
        OnClick = caracol1Click
      end
      object N20221A1: TMenuItem
        Caption = 'contreras-2022-1A'
        OnClick = N20221A1Click
      end
      object N20233R1: TMenuItem
        Caption = 'contreras-2023-3R'
        OnClick = N20233R1Click
      end
      object N202021: TMenuItem
        Caption = 'dunnia-2020_2 && 2021_1R'
        OnClick = N202021Click
      end
      object N202111: TMenuItem
        Caption = 'dunnia-2021_1'
        OnClick = N202111Click
      end
      object N202112: TMenuItem
        Caption = 'dunnia-2021_1'
        OnClick = N202112Click
      end
      object N202211: TMenuItem
        Caption = 'dunnia-2022-1'
        OnClick = N202211Click
      end
      object PMadentroToFuera1: TMenuItem
        Caption = 'dunnia-P-M-adentroToFuera'
        OnClick = PMadentroToFuera1Click
      end
      object N20222matriz1: TMenuItem
        Caption = 'dunnia-2022_2_matriz'
        OnClick = N20222matriz1Click
      end
      object N20231Matriz1: TMenuItem
        Caption = 'dunnia-2023-1-Matriz'
        OnClick = N20231Matriz1Click
      end
      object atriz1: TMenuItem
        Caption = 'shirley-matriz'
        OnClick = atriz1Click
      end
    end
  end
end
