object GameForm: TGameForm
  Left = 154
  Top = 118
  Width = 654
  Height = 451
  Caption = 'GameForm'
  Color = clBtnFace
  Constraints.MinHeight = 300
  Constraints.MinWidth = 500
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 20
  object Splitter2: TSplitter
    Left = 450
    Top = 0
    Width = 3
    Height = 374
    Cursor = crHSplit
    Align = alRight
    MinSize = 60
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 374
    Width = 646
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object PanelStatus: TPanel
    Left = 453
    Top = 0
    Width = 193
    Height = 374
    Align = alRight
    Anchors = []
    BevelOuter = bvNone
    Caption = 'PanelStatus'
    Color = clInactiveCaptionText
    TabOrder = 1
    object PageControl1: TPageControl
      Left = 0
      Top = 0
      Width = 193
      Height = 374
      ActivePage = ListQuest
      Align = alClient
      BiDiMode = bdRightToLeftNoAlign
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Images = ImageList1
      MultiLine = True
      ParentBiDiMode = False
      ParentFont = False
      TabIndex = 2
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077
        object StatusBox: TListBox
          Left = 0
          Top = 0
          Width = 185
          Height = 283
          Align = alClient
          BorderStyle = bsNone
          Color = clInactiveCaptionText
          ItemHeight = 16
          TabOrder = 0
        end
        object RadioGroup1: TRadioGroup
          Left = 0
          Top = 72
          Width = 185
          Height = 57
          Caption = #1044#1074#1080#1078#1077#1085#1080#1077' '#1087#1086' '#1084#1080#1088#1091
          ItemIndex = 1
          Items.Strings = (
            #1055#1086#1096#1072#1075#1086#1074#1086
            #1055#1091#1090#1077#1096#1077#1089#1090#1074#1080#1077)
          TabOrder = 1
          OnClick = RadioGroup1Click
        end
      end
      object TabSheet2: TTabSheet
        Caption = #1055#1088#1077#1076#1084#1077#1090#1099
        ImageIndex = 1
        object ItemsBox: TListBox
          Left = 0
          Top = 0
          Width = 185
          Height = 283
          Align = alClient
          BorderStyle = bsNone
          Color = clInactiveCaptionText
          ItemHeight = 16
          TabOrder = 0
        end
      end
      object ListQuest: TTabSheet
        Caption = #1046#1091#1088#1085#1072#1083
        ImageIndex = 2
        object JournalBox: TListBox
          Left = 0
          Top = 0
          Width = 185
          Height = 283
          Align = alClient
          BorderStyle = bsNone
          Color = clInactiveCaptionText
          ItemHeight = 16
          TabOrder = 0
          OnClick = JournalBoxClick
        end
      end
    end
  end
  object PanelLeft: TPanel
    Left = 0
    Top = 0
    Width = 450
    Height = 374
    Align = alClient
    BevelOuter = bvNone
    Caption = 'PanelLeft'
    TabOrder = 2
    object Splitter1: TSplitter
      Left = 0
      Top = 265
      Width = 450
      Height = 3
      Cursor = crVSplit
      Align = alBottom
      MinSize = 60
    end
    object PanelAction: TPanel
      Left = 0
      Top = 268
      Width = 450
      Height = 106
      Align = alBottom
      Caption = 'PanelAction'
      Color = clInactiveCaptionText
      TabOrder = 0
      object Splitter3: TSplitter
        Left = 346
        Top = 1
        Width = 3
        Height = 104
        Cursor = crHSplit
        Align = alRight
        Beveled = True
      end
      object ActionBox: TListBox
        Left = 1
        Top = 1
        Width = 345
        Height = 104
        Align = alClient
        BevelInner = bvNone
        BorderStyle = bsNone
        Color = clInactiveCaptionText
        ItemHeight = 20
        Items.Strings = (
          #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1073#1072#1079#1099' '#1076#1072#1085#1085#1099#1093)
        TabOrder = 0
        OnClick = ActionBoxClick
        OnKeyDown = FormKeyDown
      end
      object Panel1: TPanel
        Left = 349
        Top = 1
        Width = 100
        Height = 104
        Align = alRight
        BevelOuter = bvNone
        Caption = 'Panel1'
        TabOrder = 1
        object TimeBox: TMemo
          Left = 0
          Top = 0
          Width = 100
          Height = 104
          Align = alClient
          BevelInner = bvNone
          BevelKind = bkFlat
          BevelOuter = bvNone
          BorderStyle = bsNone
          Color = clInactiveCaptionText
          Lines.Strings = (
            #1044#1077#1085#1100' 1'
            #1042#1088#1077#1084#1103' 6:00'
            #1059#1090#1088#1086)
          TabOrder = 0
        end
      end
    end
    object PanelGame: TPanel
      Left = 0
      Top = 0
      Width = 450
      Height = 265
      Align = alClient
      Caption = 'PanelGame'
      Color = clInactiveCaptionText
      TabOrder = 1
      object Out: TRichEdit
        Left = 1
        Top = 1
        Width = 448
        Height = 263
        Align = alClient
        BevelInner = bvNone
        BevelOuter = bvNone
        BorderStyle = bsNone
        Color = clInactiveCaptionText
        TabOrder = 0
      end
    end
  end
  object ActionList1: TActionList
    Left = 8
    Top = 8
    object FileOpen1: TFileOpen
      Category = 'File'
      Caption = '&Open...'
      Hint = 'Open|Opens an existing file'
      ImageIndex = 7
      ShortCut = 16463
    end
    object FileSaveAs1: TFileSaveAs
      Category = 'File'
      Caption = 'Save &As...'
      Hint = 'Save As|Saves the active file with a new name'
      ImageIndex = 30
    end
    object FileExit1: TFileExit
      Category = 'File'
      Caption = 'E&xit'
      Hint = 'Exit|Quits the application'
      ImageIndex = 43
    end
    object FileRun1: TFileRun
      Category = 'File'
      Browse = False
      BrowseDlg.Title = 'Run'
      Caption = '&Run...'
      Hint = 'Run|Runs an application'
      Operation = 'open'
      ShowCmd = scShowNormal
    end
    object EditCut1: TEditCut
      Category = 'Edit'
      Caption = 'Cu&t'
      Hint = 'Cut|Cuts the selection and puts it on the Clipboard'
      ImageIndex = 0
      ShortCut = 16472
    end
    object FontEdit: TFontEdit
      Category = 'Dialog'
      Caption = #1064#1088#1080#1092#1090'...'
      Dialog.Font.Charset = DEFAULT_CHARSET
      Dialog.Font.Color = clWindowText
      Dialog.Font.Height = -11
      Dialog.Font.Name = 'MS Sans Serif'
      Dialog.Font.Style = []
      Dialog.MinFontSize = 0
      Dialog.MaxFontSize = 0
      Hint = #1042#1099#1073#1086#1088' '#1096#1088#1080#1092#1090#1072
      OnAccept = FontEditAccept
    end
  end
  object MainMenu1: TMainMenu
    Left = 40
    Top = 8
    object Open1: TMenuItem
      Caption = #1060#1072#1081#1083
      Hint = 'Open|Opens an existing file'
      ImageIndex = 7
      ShortCut = 16463
      object Open2: TMenuItem
        Action = FileOpen1
      end
      object SaveAs1: TMenuItem
        Action = FileSaveAs1
      end
      object Run1: TMenuItem
        Action = FileRun1
      end
      object Exit1: TMenuItem
        Action = FileExit1
      end
    end
    object N1: TMenuItem
      Caption = #1055#1088#1072#1074#1082#1072
      object Cut1: TMenuItem
        Action = EditCut1
      end
      object SelectFont1: TMenuItem
        Action = FontEdit
      end
    end
    object N2: TMenuItem
      Caption = #1054#1090#1083#1072#1076#1082#1072
      object NDebug: TMenuItem
        Caption = #1054#1090#1083#1072#1076#1086#1095#1085#1072#1103' '#1092#1086#1088#1084#1072'...'
        OnClick = NDebugClick
      end
    end
    object N4: TMenuItem
      Caption = #1048#1075#1088#1072
      object NStart: TMenuItem
        Caption = #1053#1072#1095#1072#1090#1100
        OnClick = NStartClick
      end
    end
  end
  object ImageList1: TImageList
    Height = 24
    Width = 24
    Left = 40
    Top = 40
    Bitmap = {
      494C010103000400040018001800FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000600000001800000001002000000000000024
      000000000000000000000000000000000000000000000000000000000000F7F6
      F6007871700095918F0000000000000000000000000000000000B0AEE0008C8A
      D2008C8AD200B0AEE0000000000000000000000000000000000095908F007771
      6F00F6F6F6000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007EAFF3004C95EF002F90EF003898
      F2003F9CF200318FEF004A93EF007EAFF3000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000AFCFEB00609ED7002284D000057ED0000C74
      C1000C74C100057CD0002082D000609ED700AFCFEB0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00006F696700706A6000B8B6B5008785D400201DC2001815D1001A17E2001C19
      EF001C19EF001A17E2001815D100201DC2008785D400B9B5B5006E685F007068
      6600000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F9F9F900837C7E001D7EF400329BFB003097FA002F97
      FA002E96FA003A9DFA0053AEFC002A86F400837B7E00F9F9F900000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000BFD9F0002081CE000D99DC001CC4F40023D7FF001FD0FD0018C1
      F60018C1F70022CFFF0021CDFF0016B9F7000A91DF00207ECE00BFD9F0000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000989489004D466F00140EC000201FF0001D1EF9002323F5004340F100625D
      EC00635DEC004340F1002323F5001D1EF900201FF000130EC1004C466E009793
      8800000000000000000000000000000000000000000000000000000000000000
      0000000000009F999C00675C6300C0B5AD001E6EE200257DF900257CF700257C
      F700257CF700237BF700378DFA002A79E200C4B8B000675E65009E999C000000
      0000000000000000000000000000000000000000000000000000000000000000
      000070ABDD000A8FD40021D3F4001DC6EF000FA1E000038BD800028DDB00028F
      DC000391DD000493DF000BA3E50013B6F2001AC9FF0018C0FA000A91DF0070AB
      DD00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00008E8BC2001616DC002326FA002227F5007F7AE600AEA0D100847AC600928A
      C8009188C700857BC700B0A2D300817CE7002227F5002326FA001616DC008E8B
      C200000000000000000000000000000000000000000000000000000000000000
      00006A62660089828400D8D7D700EEE7E0004183D4001D66F9002168F6002168
      F6002168F6001F67F6004086FA00518FD700EFEBE500DDDBDB008D8487006A61
      65000000000000000000000000000000000000000000000000000000000060A3
      DB0017B3E20024DAF4000990D5000090D90000A9E70000AEEB000992D800098F
      D800098CD7000989D5000393E2000298E50008A3E70013BCF50021CDFF000FA3
      E80060A3DB000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000BFBD
      EB001E20DF00242CF700383DF200A498D300E9E7FA00F7F7F300EDECE300DAD8
      D6003C3B4000DCDBD200CECCCB00B1ACB800A79BD600383DF300242CF7001E20
      DF00BFBDEB000000000000000000000000000000000000000000000000007B72
      7600A29DA000DBD9D900E7E6E600FBF7F3007EABDC001150EE001C58F6001C58
      F5001C58F5001A56F6002C6EEC0091B5DE00FBF8F400EAE9E900DFDEDE00A7A2
      A4007B727600000000000000000000000000000000000000000070AFE0001EB6
      E40025D7EF00027BCD0000AEE40000BDEC0000B8EC00099DDA001E5EA5001E5E
      A5001E5EA5001E5EA5001E5EA5000098E7000094E600049EE70011BAF30021CF
      FF0011A5E90070AFE00000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000001B19
      CB002834F7003B44F100988ED200DEDBE700F7F7F30064646A00E5E4E200DAD8
      D600DAD8D600DAD8D600CECCCB003C3B4000B1ACB8009890D3003C45F2002834
      F7001B19CB000000000000000000000000000000000000000000B1ACAE008D84
      8900D9D8D700E8E8E800F4F3F300F5F3F100C5D2DF000742E0001B50F8001B50
      F6001B50F6001B50F8002462DF00D1DAE200F3F0EF00F5F4F400EDECEB00DFDE
      DE0092898D00B1ACAE00000000000000000000000000BFDCF2001799D9003CE0
      F3000078CB0000BCE80000C7EE0000C2ED0000BEEB0008A2DA001978C2001FC6
      FF001FC6FF001FAAEA000F67B40000A0E800009AE7000097E700029DE80011BE
      F40022D1FF000990DB00F5FAFD00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000008A86DD002938
      F0002333F6008581D800E3DFEB00F7F7F300F7F7F300E4E3E200DFDEDD00DEDC
      DA00D7D5D400CFCDCC00CFCDCC00C5C3C100C3C0BC00B1AAB6008B86DE002333
      F6002938F0008A86DD00000000000000000000000000FAF9F9006D626800D3D1
      D100E5E3E400F4F3F300F0F0F000EBEAE900FCF6E900003AD0001348DC001248
      D8001147D7001E54E5000845C600F9F1E700E9E7E700EFEEEE00F5F4F400EAE8
      E800DADAD8006F646900FAF9F9000000000000000000278FD6004DE3F4000C7F
      CD0000C5EB0000D7F30000CEF00000CAEF0000C4ED0007A8DD001877BE0020C9
      FF0021C7FF001FABE9000E68B10000A6E90000A1E800009DE8000099E60005A8
      EB0018CAF9001DC9F90064C3ED00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000001F22D7002B40
      F6003E4DF200E9E7FA0064646A00EBEAEA00EBEAEA00E4E3E200DDDCDB00D8D6
      D500D2D0CF00CDCBCA00C7C5C400C5C3C200C5C3C2003C3B4000B1AAB600404F
      F4002B40F6001F22D7000000000000000000000000008A8B9A00B3A69D00E8E3
      DC00F8F6F100F6F4F200ECEAE900E5E5E6008C817E00627DB300D2DCF100CDD8
      EF00CDD8EF00D2DCF1006880AC008A7E8000E3E4E300E9E8E700F4F2EF00FCF8
      F400F0EBE400BAADA4008B8C9A0000000000AFD6F0002FAFE20021D3F400009D
      D90002E3F50001DDF40000D8F30000D2F20000CBF00007ADDE00177BBE0022D0
      FF0021D0FF0022B2E8000E68B30000ABEA0000A7E90000A3E800009FE800009C
      E8000AB6F00023D7FF0010A2E200BDE4F7000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000CECDF3002832E4002A41
      F5005E63DF00FDFAFF00FDFAFF00F1F1F000E9E8E800E3E2E100DDDCDB00D8D6
      D500D2D0CF00CDCBCA00C7C5C400C2C0BF00C2C0BF00BAB9B600ACA8AB006369
      E6002A41F5002832E400CECDF300000000007EAFF4003191F6002B7CE4003C80
      D40093B7E000C2D1E100FBF5EA0090838200D1CBCB0000000000000000000000
      0000000000000000000000000000D1CBCC0091838100EDEAE500C4D1DF0080AC
      DB004486D7001366E2001D7DF2007EAFF30085CDF0005EDDF300009DD90006DD
      F00001EAF70002E6F60001DFF50000DBF40000D5F20008B4E0001980BD0023DB
      FF0023DAFF0024B9E8000C6EB50000B3EC0000AEEB0000A9EA0000A6E90000A0
      E80004ABED001ACFF9001DCAF6009AD6F2000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000009B97E8002C40EE002B44
      F5008684DD000000000000000000F1F1F000E9E8E800E3E2E100DFDEDC00E2E0
      DE00DFDDDB00D8D6D500D0CECC00C8C6C500C1BEBD00BDBBB900BAB7AB00807F
      D8002C46F6002C40EE009B97E800000000004B95F0005CB7FC003A92FA003E89
      FA003577F0002564E0000D4ACC006881B0000000000000000000000000000000
      0000000000000000000000000000000000005177C000003BCF000842E5001250
      F0001D66F900257DF900319BFB004C95EF0062BFEB0074ECF9001A9FD9001EEF
      F8000BEEF70002ECF70002E8F60002E1F50000DCF40009BAE1001886BC0026E5
      FC0026E3FC0026C2E6000B74B70000B8EC0000B5ED0000B0EC0000AAEA0000A7
      E90000A7EB0013C6F50025E0FD0062BFEB000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000008985E6004960F5002C48
      F5007676EA0064646A00F6F6F500F6F6F500E9E8E800E3E2E100E6E5E3002C2B
      2E002C2B2E003C3B4000434245005F5D5F006E6D7000BDBBB9003C3B40006260
      D3002E4AF7004960F5008985E600000000003191F1003CA3FB002581F7001F6C
      F6001B5BF600184FF7002055EC00AABDE5000000000000000000000000000000
      000000000000000000000000000000000000BFCDEB001449E3001B50F7001C58
      F6002168F600257CF7003097FA002F8FEF0045B3E70064D0EE001A9FD90035F0
      F70024F0F70013EFF80004EDF70002E9F70002E5F5000AC3E200198EBD002BEB
      F9002BEBF9002BCAE6000B7ABA0000BEEB0000BBEC0000B6EC0000B2EC0000AD
      EB0000A8EA0010C3F40026E5FB0045B3E7000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000008A85E9005D72F1003A53
      F4005656EB00F6F4F500F6F4F500F6F4F500EBEAE800E6E5E400EDEAEA002C2B
      2E002C2B2E003C3B4000434245005F5D5F006E6D7000D6D4D000D6D4D0004040
      D4003B54F6005D72F1008A85E90000000000409FF300339DFA002783F700216D
      F6001D5DF5001B52F6001247DC00CFD9EF000000000000000000000000000000
      000000000000000000000000000000000000CED9EF001248D7001B50F6001C58
      F5002168F600257CF7002F97FA003898F200269CDD006AD0EE001A9FD9004AF1
      F9003BF1F8002BF0F70019EEF80008EEF70002EBF7000ACAE6002095BF0040F2
      F9003EF1F90036D0E7000A81BD0000C4ED0000C1ED0000BCEC0000B7EC0000B4
      EC0000AEEB0009B9F20029E9FA00269CDD000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000009995ED004B56EA006275
      EE002C36E90000000000FFFEFE00F4F4F400F0EFEF00EBEBEA00EFEEED007372
      7400EBE9E800E1DFDD00DDDBDB00D8D6D500D6D4D000D6D4D000D2D0CF003E48
      EC00697BEF004A55EA009995ED0000000000399CF300349DFA002783F700216D
      F6001D5DF5001B52F6001148D700CED9EF000000000000000000000000000000
      000000000000000000000000000000000000CED9EF001147D7001B50F6001C58
      F5002168F600257CF7002E97FA003F9DF200269CDD0084D7F1003BAEDE005BF1
      F80050F1F90041F1F80031F0F70021EFF8000FEFF8000CD0E7002A99C5005BF2
      FA0059F2FA004BD3E8000A88C10000CBF00000C6EE0000C1ED0000BEEC0000BA
      EC0006B8EF0023C1F20059F1FA00269CDD000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000E1E0FB002F3FEE00A2AB
      EA005966F300E9E7FA00F3F3F000F3F3F000F3F2F200EAEAE900EDECEA00908F
      9000EBE9E800E1DFDD00D5D3D300D1CFCE00D2D0CF00D2D0CF00BAB6C9005B68
      F700758AF9004350EF00E1DFFB00000000002F91F100349EFA002783F700216D
      F6001D5DF6001B52F600174AEB00C0CEEB000000000000000000000000000000
      000000000000000000000000000000000000BECDEB001F54E800184DF7001A56
      F6001F67F600237BF700399CFA003090EF0046B0E50099DDF4003BAEDE008CF5
      FA0077F4F90061F2F9004CF2F90037F1F80026F0F7001AD2E80033A2C80072F4
      FB0071F4FB005CD7EA000A91C20000D5F20000CDF0000BCFF4001ACFF4002FCF
      F4003DCEF4004DD5F60064F4FA002CB0E5000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000004143EB00B9BE
      ED007388F7008683F40064646A00F3F2F200F3F2F200ECECEB00ECEBE9009795
      9600EBE9E800E0DEDC00D6D4D400D4D2D100D4D2D1003C3B4000746FE100758A
      F900A3B0EF004043EB0000000000000000004C97F00037A1FB002884F9001E6C
      F9001454F2000845E600003ACF003C67BB000000000000000000000000000000
      0000000000000000000000000000000000006C88B7000B48CB002462DF003472
      F0003D83F900378DFA0059B2FC004A93EF0052B6E800B9F2FC0057A4DB009CF7
      FA0094F5FA008BF6F9007DEBF40058DCEC0058DCEC0053DDED00409AC30092F6
      FE0093F6FD0085E1F0002CABD10038E4F7003FE1F7003DDDF6003DDBF6003CD7
      F5003ED2F50055D9F60071F5FB0075C8EE000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000008984F1007388
      F500BBBFEA005B70F800C1BDF800F3F3F000F4F3F200F4F3F200F4F3F200ADAB
      AC00EBE9E800DFDDDC00D7D5CA00D7D5CA00D7D5CA009F98D3005E72FB009FB1
      F4007085F5008A84F10000000000000000007EAFF4001C81F2001368E3003077
      D5007FADDC00C7D6E200EEEDE600A99B9800DBD6D50000000000000000000000
      0000000000000000000000000000DBD5D500A69A9800F9F3E800C1CFDF0093B7
      DE003D7FD3002A77E2002D8BF1007EAEF2006CC1EC00B0EDF90056A1DB0099E9
      F600A0F6FA0098F5FA0056ADD20056ADD20056ADD200409AC300409AC300AEF8
      FF00ADF8FF0097E5F3002CABD10041EBF80041E7F8003FE4F7003EDEF7003DDB
      F60041D1F5006BE7F90077E9F70096D5F2000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000003635
      ED00A4B3F000B2B9EC005461F600BAB6F300E7E6D90064646A00F1F0EE00ADAB
      AC00EBE9E800E1DFDC00D1D0CA003C3B40009993DC005865FA00B3BAEC006878
      F8003635ED0000000000000000000000000000000000A3A5B200BEB0A600E7DF
      D700F7F3EE00F8F5F300EDECEC00E6E6E600AC9D9B00718BB800D2DCF100CDD8
      EF00CDD8EF00D2DCF1006986BB00AB9E9A00E5E4E400EAEAE900F5F3F100F9F7
      F300EBE5DE00C1B7AD00A2A3AF0000000000B2DFF50077CDF00093D1ED0074C1
      E600A8F7FC00A3F6FC0047AFD200A1E8F500BBFBFF00ADF0F900A0E8F500B9F9
      FF00B7F9FF009EE7F4003BC1DD0041F1F90041ECF80041E9F80040E4F7003FDF
      F7004ACEF50085F3FC005BCCEE00AEDEF5000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00003639F100BAC3ED00BBC0EB006679F800797CF700E7E6D900ECEAE900B2B1
      A5003C3B4000DFDCDA00D1D0CA00B2B0AA00687CFA00BBC1EB006878F800373A
      F100EFEFFE0000000000000000000000000000000000FCFBFB00978B8F00C9C9
      C600E1DFDF00F1F1F100F2F1F100ECEBEB00FBF5EA000744C6001D53E5001147
      D7001248D7001247DD000039D000FBF5E800EAE9E900F0F0F000F4F3F300E5E4
      E400D1D0D000988C8F00FCFBFB00000000000000000063C9F100BDF3FD0056A1
      DB0096E4F400ABF8FC0047AFD20056CFE400C2FBFF00C1FBFF00C0FCFF00C0FC
      FF00BFFCFF00A3E9F60042C9E0004AF4FA0043F2F90040EDF80041EAF80045D5
      F50073E2F90092EFFA0057C8F000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000262DF100666FF800B7BC
      FC00B4B0FA004043F5009FB1F400D2D1E600A3B0EF007386F8005863FA005A62
      FD005A64FE005966FB007487F900A4B0F0009FB1F4006878F8004043F500B5B1
      FA009998F9002C23F4002017F200000000000000000000000000CCC6C900A79F
      A200CFCECD00E3E2E200F2F1F100F7F5F300D4DDE5002462E0001B52F8001B50
      F6001B51F6001B51F8000744E100C6D3E000F5F4F100F4F3F300E7E8E800D5D5
      D400AAA3A700CCC6C800000000000000000000000000C2E8F90063C9F100B4E7
      F7004D9CDA00A4F1F9008EE4F10057BEDA005CBDDD0056CFE400C5FBFF00C4FB
      FF00C4FBFF00A6EAF7004ACCE3005DF3F90050F4FA0045F3F90043DEF60068D9
      F600A2F7FD0057C8F000C2E8F900000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000004052F5006C7CF7003B51
      F4003045F6005C5FDE002F2AD9006878F800CDCEE900CDCEE900D9D8E600C5C8
      EA00C5C8EA00C5C8EA00C5C8EA00A8B5F0006774F7002E2ADA00565BD6002F3D
      F500262CF2002221F1002017F20000000000000000000000000000000000B0A6
      A800B1ABAC00CFCECE00E1E1E100F6F2EE0091B6E0002D70EC001B5BF6001D5C
      F5001D5CF5001D5CF6001252EE0080ACDD00FAF6F200E6E4E400D5D3D300B6B0
      B100AFA6A700000000000000000000000000000000000000000078CFF30093DF
      F700B5E7F7004EA0DB0090DFF200ABF8FC0094E7F3005CC1DD0057B9D8005EBD
      DD0057B9D80057B9D80056CFE4006FF4FA0061F3F9004BD9F40065D2F400A4F5
      FE0082DEF60078CFF30000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000005167F5006D82F8003652
      F500344DF4002B3CF5003236F4005F58F600524EF5004149F6005C6DF7006375
      F8006375F8005C6DF7003F45F6004E47F5006C6FF7004059F700324CF6002F46
      F4002B3BF300262CF200201DF200000000000000000000000000000000000000
      0000ABA0A400AEA4A800C9C8C800E5DFD9004E89D500418AFA001F6BF600216C
      F600216CF600216CF6001D6AF9004082D500E9E1DB00CDCCCC00B0A7A900AAA0
      A3000000000000000000000000000000000000000000000000000000000071CE
      F20094E1F700C0EFFB0063B0E10068BDE70097E7F500ABF8FC009CEFF7008CE7
      F20087E6F20080E6F20082F2F70067DCF4004AC0ED007BDBF500B8F9FE0087DF
      F60071CEF2000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C1CAFD00728AF9004260
      F6003B55F5002F45F3002730F2001F19F2004740F500CFCDFC00000000000000
      00000000000000000000D1D4FD008495F9006C81F8003956F5003C57F5003750
      F4002F46F3002A36F200B3B4FB00000000000000000000000000000000000000
      000000000000CCC5C700A89DA000C6BAB1002979E1003992FA002580F7002781
      F7002781F7002781F7002783F9001C6FE100C9BEB600A99DA100CCC5C7000000
      0000000000000000000000000000000000000000000000000000000000000000
      000079D4F40062CFF400C2F4FE00ADE3F6006CBBE80056B0E4005CB9E70062C0
      E90061C2EA0058C0EA0053BBEA0078D3F200B1F1FC00B8F3FD005ECFF40079D4
      F400000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000D4DCFD004A67
      FD003853F8002F45F4002730F2001F19F2002017F2008681F800000000000000
      000000000000000000008E9CF900455EF600778DF900657FF7004562F6003B57
      F800354EFC00B8BFFC0000000000000000000000000000000000000000000000
      00000000000000000000FCFCFC00C1B8BC002686F10058B6FC003CA3FB00339D
      FA00349DFA00349EFA0037A2FB00197FF200C2B9BB00FCFCFC00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000C2ECFB0044C6F2007ADAF800BBF2FD00D5FCFF00BEF1FC00ACE6
      F700ACE7F800CAFCFF00CDFCFF00B6F1FC0077DAF7005ECFF400C2ECFB000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000009C93
      8400929DE8004756F7002527F2001F17F2007772F80000000000000000000000
      00000000000000000000000000008696F9004E69F7006F88F8008299FA00A0AB
      EA00918974000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000007DAFF4004B95F0003191F100409F
      F300399CF3002D8FF1004D97F0007EAFF4000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000B4E9FB0071D6F60059D0F6004BCEF6004AC0
      ED004AC0ED004BCEF60059D0F60074D6F700B7EAFB0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000060000000180000000100010000000000200100000000000000000000
      000000000000000000000000FFFFFF00E3C3C7FF00FFFE007F000000F0000FFC
      003FF8001F000000F0000FF8001FF0000F000000F0000FF0000FE00007000000
      E00007E00007C00003000000E00007C00003800001000000C000038000018000
      01000000C00003800001000000000000800001007E0000000000000086000100
      FF0000000000000080000100FF0000000000000080000100FF00000000000000
      84000100FF0000000000000080000100FF00000000000000C0000300FF000000
      00000000C00003007E00000000000000E00007800001000000000000F0000780
      0001800001000000800001C00003800001000000800001E00007C00003000000
      800001F0000FE00007000000803C01F8001FF0000F000000C03C03FC003FF800
      1F000000E07E07FF00FFFE007F00000000000000000000000000000000000000
      000000000000}
  end
  object ImageList2: TImageList
    Left = 8
    Top = 40
  end
end