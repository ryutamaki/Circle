<GameProjectFile>
  <PropertyGroup Type="Scene" Name="PowerUpScene" ID="dcbabf22-44d5-46ba-abfc-4ccf1ccb552a" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" Visible="False" Tag="6" ctype="GameNodeObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Background" ActionTag="1270772589" Tag="13" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-187.0000" RightMargin="-187.0000" TopMargin="-110.0000" ctype="SpriteObjectData">
            <Size X="1334.0000" Y="750.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position X="480.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" />
            <PreSize X="1.3896" Y="1.1719" />
            <FileData Type="Normal" Path="Images/Background@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="PowerUpLabel" ActionTag="-268652109" Tag="15" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="364.0000" RightMargin="364.0000" TopMargin="28.8000" BottomMargin="555.2000" LabelText="POWER UP" ctype="TextBMFontObjectData">
            <Size X="232.0000" Y="56.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="480.0000" Y="611.2000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.9550" />
            <PreSize X="0.2417" Y="0.0875" />
            <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="BackButton" ActionTag="283203610" Tag="29" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="96.0000" RightMargin="792.0000" TopMargin="28.8000" BottomMargin="567.2000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="42" Scale9Height="22" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="72.0000" Y="44.0000" />
            <AnchorPoint ScaleY="1.0000" />
            <Position X="96.0000" Y="611.2000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1000" Y="0.9550" />
            <PreSize X="0.0750" Y="0.0688" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="Images/BackButtonPushed@2x.png" Plist="" />
            <NormalFileData Type="Normal" Path="Images/BackButtonNormal@2x.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="CoinLayout" ActionTag="1665831279" Tag="60" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="476.0000" RightMargin="284.0000" TopMargin="109.0000" BottomMargin="301.0000" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" ctype="PanelObjectData">
            <Size X="200.0000" Y="230.0000" />
            <Children>
              <AbstractNodeData Name="CoinLabel" ActionTag="-1332992539" Tag="59" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="64.0000" RightMargin="64.0000" TopMargin="56.1000" BottomMargin="138.9000" LabelText="COIN" ctype="TextBMFontObjectData">
                <Size X="72.0000" Y="35.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="156.4000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.6800" />
                <PreSize X="0.3600" Y="0.1750" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/CircleFont30_Red.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Line" ActionTag="-1212488909" Tag="67" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="88.0000" RightMargin="88.0000" TopMargin="90.0000" BottomMargin="136.0000" ctype="SpriteObjectData">
                <Size X="24.0000" Y="4.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="138.0000" />
                <Scale ScaleX="5.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.6000" />
                <PreSize X="0.1200" Y="0.0200" />
                <FileData Type="Normal" Path="Images/Line_Red@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="CoinCountLabel" ActionTag="-1117650949" Tag="71" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="85.5000" RightMargin="85.5000" TopMargin="110.0000" BottomMargin="64.0000" LabelText="0" ctype="TextBMFontObjectData">
                <Size X="29.0000" Y="56.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="92.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.4000" />
                <PreSize X="2.0300" Y="0.2800" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/CircleFont48_Red.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="576.0000" Y="416.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.6000" Y="0.6500" />
            <PreSize X="0.2083" Y="0.3594" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="RankLayout" ActionTag="411641937" Tag="61" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="140.0000" RightMargin="620.0000" TopMargin="365.0000" BottomMargin="45.0000" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" ctype="PanelObjectData">
            <Size X="200.0000" Y="230.0000" />
            <Children>
              <AbstractNodeData Name="RankUpButton" ActionTag="-1010759929" Tag="72" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="50.0000" RightMargin="50.0000" TopMargin="99.5000" BottomMargin="30.5000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="70" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="100.0000" Y="100.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="80.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.3500" />
                <PreSize X="0.5000" Y="0.4348" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="Images/StatusUpButtonPushed@2x.png" Plist="" />
                <PressedFileData Type="Normal" Path="Images/StatusUpButtonPushed@2x.png" Plist="" />
                <NormalFileData Type="Normal" Path="Images/StatusUpButtonNormal@2x.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="RankLabel" ActionTag="75060933" Tag="54" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="64.0000" RightMargin="64.0000" TopMargin="17.0000" BottomMargin="178.0000" LabelText="RANK" ctype="TextBMFontObjectData">
                <Size X="72.0000" Y="35.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="195.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.8500" />
                <PreSize X="0.3600" Y="0.1750" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/CircleFont30.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Line" ActionTag="-503055104" Tag="64" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="88.0000" RightMargin="88.0000" TopMargin="50.9000" BottomMargin="175.1000" ctype="SpriteObjectData">
                <Size X="24.0000" Y="4.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="177.1000" />
                <Scale ScaleX="5.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.7700" />
                <PreSize X="0.1200" Y="0.0200" />
                <FileData Type="Normal" Path="Images/Line@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="RankLevelLabel" ActionTag="-563430564" Tag="68" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="85.5000" RightMargin="85.5000" TopMargin="70.9000" BottomMargin="103.1000" LabelText="0" ctype="TextBMFontObjectData">
                <Size X="29.0000" Y="56.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="131.1000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5700" />
                <PreSize X="0.1450" Y="0.2800" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="RankUpCoinNeedCountLabel" ActionTag="-679035429" Tag="75" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="93.0000" RightMargin="93.0000" TopMargin="193.0000" BottomMargin="9.0000" LabelText="0" ctype="TextBMFontObjectData">
                <Size X="14.0000" Y="28.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="23.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.1000" />
                <PreSize X="0.0700" Y="0.1217" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/CircleFont24_Red.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="240.0000" Y="160.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.2500" Y="0.2500" />
            <PreSize X="0.2083" Y="0.3594" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="HpLayout" ActionTag="-5127974" Tag="62" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="380.0000" RightMargin="380.0000" TopMargin="365.0000" BottomMargin="45.0000" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" ctype="PanelObjectData">
            <Size X="200.0000" Y="230.0000" />
            <Children>
              <AbstractNodeData Name="HpUpButton" ActionTag="1104036888" Tag="73" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="50.0000" RightMargin="50.0000" TopMargin="99.5000" BottomMargin="30.5000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="70" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="100.0000" Y="100.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="80.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.3500" />
                <PreSize X="0.5000" Y="0.4348" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="Images/StatusUpButtonPushed@2x.png" Plist="" />
                <PressedFileData Type="Normal" Path="Images/StatusUpButtonPushed@2x.png" Plist="" />
                <NormalFileData Type="Normal" Path="Images/StatusUpButtonNormal@2x.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="HpLabel" ActionTag="-1037608615" Tag="57" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="82.0000" RightMargin="82.0000" TopMargin="17.0000" BottomMargin="178.0000" LabelText="HP" ctype="TextBMFontObjectData">
                <Size X="36.0000" Y="35.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="195.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.8500" />
                <PreSize X="0.1800" Y="0.1750" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/CircleFont30.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Line" ActionTag="1550760744" Tag="65" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="88.0000" RightMargin="88.0000" TopMargin="50.9000" BottomMargin="175.1000" ctype="SpriteObjectData">
                <Size X="24.0000" Y="4.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="177.1000" />
                <Scale ScaleX="5.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.7700" />
                <PreSize X="0.1200" Y="0.0200" />
                <FileData Type="Normal" Path="Images/Line@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="HpLevelLabel" ActionTag="-514259335" Tag="69" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="85.5000" RightMargin="85.5000" TopMargin="70.9000" BottomMargin="103.1000" LabelText="0" ctype="TextBMFontObjectData">
                <Size X="29.0000" Y="56.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="131.1000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5700" />
                <PreSize X="0.1450" Y="0.2800" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="HpUpCoinNeedCountLabel" ActionTag="750537111" Tag="76" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="93.0000" RightMargin="93.0000" TopMargin="193.0000" BottomMargin="9.0000" LabelText="0" ctype="TextBMFontObjectData">
                <Size X="14.0000" Y="28.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="23.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.1000" />
                <PreSize X="0.0700" Y="0.1217" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/CircleFont24_Red.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="160.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.2500" />
            <PreSize X="0.2083" Y="0.3594" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="AttackLayout" ActionTag="-1722015390" Tag="63" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="620.0000" RightMargin="140.0000" TopMargin="365.0000" BottomMargin="45.0000" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" ctype="PanelObjectData">
            <Size X="200.0000" Y="230.0000" />
            <Children>
              <AbstractNodeData Name="AttackUpButton" ActionTag="1164381266" Tag="74" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="50.0000" RightMargin="50.0000" TopMargin="99.5000" BottomMargin="30.5000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="70" Scale9Height="78" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="100.0000" Y="100.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="80.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.3500" />
                <PreSize X="0.5000" Y="0.4348" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Normal" Path="Images/StatusUpButtonPushed@2x.png" Plist="" />
                <PressedFileData Type="Normal" Path="Images/StatusUpButtonPushed@2x.png" Plist="" />
                <NormalFileData Type="Normal" Path="Images/StatusUpButtonNormal@2x.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="AttackLabel" ActionTag="419633433" Tag="58" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="46.0000" RightMargin="46.0000" TopMargin="17.0000" BottomMargin="178.0000" LabelText="ATTACK" ctype="TextBMFontObjectData">
                <Size X="108.0000" Y="35.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="195.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.8500" />
                <PreSize X="0.5400" Y="0.1750" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/CircleFont30.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Line" ActionTag="-2069967731" Tag="66" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="88.0000" RightMargin="88.0000" TopMargin="50.9000" BottomMargin="175.1000" ctype="SpriteObjectData">
                <Size X="24.0000" Y="4.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="177.1000" />
                <Scale ScaleX="5.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.7700" />
                <PreSize X="0.1200" Y="0.0200" />
                <FileData Type="Normal" Path="Images/Line@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="AttackLevelLabel" ActionTag="-130950972" Tag="70" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="85.5000" RightMargin="85.5000" TopMargin="70.9000" BottomMargin="103.1000" LabelText="0" ctype="TextBMFontObjectData">
                <Size X="29.0000" Y="56.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="131.1000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5700" />
                <PreSize X="0.1450" Y="0.2800" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="AttackUpCoinNeedCountLabel" ActionTag="-1983240853" Tag="77" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="93.0000" RightMargin="93.0000" TopMargin="193.0000" BottomMargin="9.0000" LabelText="0" ctype="TextBMFontObjectData">
                <Size X="14.0000" Y="28.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="100.0000" Y="23.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.1000" />
                <PreSize X="0.0700" Y="0.1217" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/CircleFont24_Red.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="720.0000" Y="160.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7500" Y="0.2500" />
            <PreSize X="0.2083" Y="0.3594" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>