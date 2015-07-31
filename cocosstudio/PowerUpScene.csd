<GameProjectFile>
  <PropertyGroup Type="Scene" Name="PowerUpScene" ID="dcbabf22-44d5-46ba-abfc-4ccf1ccb552a" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" Tag="6" ctype="GameNodeObjectData">
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
          <AbstractNodeData Name="HpComponent" ActionTag="1674436308" Tag="44" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentWidthEnabled="True" LeftMargin="95.9998" RightMargin="624.0002" TopMargin="326.0000" BottomMargin="64.0000" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" Scale9Enable="True" LeftEage="8" RightEage="8" TopEage="8" BottomEage="8" Scale9OriginX="8" Scale9OriginY="8" Scale9Width="84" Scale9Height="84" ctype="PanelObjectData">
            <Size X="240.0000" Y="250.0000" />
            <Children>
              <AbstractNodeData Name="HpLabel" ActionTag="587467033" Tag="54" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="91.0000" RightMargin="91.0000" TopMargin="28.0000" BottomMargin="196.0000" LabelText="HP" ctype="TextBMFontObjectData">
                <Size X="58.0000" Y="56.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0000" Y="200.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.8000" />
                <PreSize X="0.1208" Y="0.3111" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Line" ActionTag="1419790351" Tag="53" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="108.0000" RightMargin="108.0000" TopMargin="82.0000" BottomMargin="194.0000" ctype="SpriteObjectData">
                <Size X="24.0000" Y="4.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0000" Y="175.0000" />
                <Scale ScaleX="7.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.7000" />
                <PreSize X="0.1000" Y="0.0222" />
                <FileData Type="Normal" Path="Images/Line@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="HpLevelLabel" ActionTag="1384261388" Tag="26" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="99.0000" RightMargin="99.0000" TopMargin="97.0000" BottomMargin="72.0000" LabelText="0" ctype="TextBMFontObjectData">
                <Size X="42.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0000" Y="112.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.4500" />
                <PreSize X="0.1750" Y="0.3375" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo70.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="HpLevelUpButton" ActionTag="236778797" Tag="21" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" TopMargin="177.0000" BottomMargin="-23.0000" TouchEnable="True" FontSize="16" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="210" Scale9Height="74" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="240.0000" Y="96.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0000" Y="25.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.1000" />
                <PreSize X="0.2500" Y="0.1500" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Images/LevelUpButtonPushed@2x.png" Plist="" />
                <NormalFileData Type="Normal" Path="Images/LevelUpButtonNormal@2x.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position X="95.9998" Y="64.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1000" Y="0.1000" />
            <PreSize X="0.2500" Y="0.3906" />
            <FileData Type="Normal" Path="Images/ComponentFrame@2x.png" Plist="" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="AttackComponent" ActionTag="1324021301" Tag="45" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentWidthEnabled="True" LeftMargin="360.0000" RightMargin="360.0000" TopMargin="326.0000" BottomMargin="64.0000" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" Scale9Enable="True" LeftEage="8" RightEage="8" TopEage="8" BottomEage="8" Scale9OriginX="8" Scale9OriginY="8" Scale9Width="84" Scale9Height="84" ctype="PanelObjectData">
            <Size X="240.0000" Y="250.0000" />
            <Children>
              <AbstractNodeData Name="AttackLabel" ActionTag="-44778528" Tag="56" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="33.0000" RightMargin="33.0000" TopMargin="22.0000" BottomMargin="172.0000" LabelText="ATTACK" ctype="TextBMFontObjectData">
                <Size X="174.0000" Y="56.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0000" Y="200.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.8000" />
                <PreSize X="0.7250" Y="0.3111" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Line" ActionTag="350932942" Tag="55" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="108.0000" RightMargin="108.0000" TopMargin="73.0000" BottomMargin="173.0000" ctype="SpriteObjectData">
                <Size X="24.0000" Y="4.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0000" Y="175.0000" />
                <Scale ScaleX="7.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.7000" />
                <PreSize X="0.1000" Y="0.0222" />
                <FileData Type="Normal" Path="Images/Line@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="AttackLevelLabel" ActionTag="-1502864414" Tag="27" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="99.0000" RightMargin="99.0000" TopMargin="97.0000" BottomMargin="72.0000" LabelText="0" ctype="TextBMFontObjectData">
                <Size X="42.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0000" Y="112.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.4500" />
                <PreSize X="0.1750" Y="0.3375" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo70.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="AttackLevelUpButton" ActionTag="639465357" Tag="23" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="0.0000" RightMargin="0.0000" TopMargin="177.0000" BottomMargin="-23.0000" TouchEnable="True" FontSize="16" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="210" Scale9Height="74" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="240.0000" Y="96.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0000" Y="25.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.1000" />
                <PreSize X="0.2500" Y="0.1500" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Images/LevelUpButtonPushed@2x.png" Plist="" />
                <NormalFileData Type="Normal" Path="Images/LevelUpButtonNormal@2x.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" />
            <Position X="480.0000" Y="64.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.1000" />
            <PreSize X="0.2500" Y="0.3906" />
            <FileData Type="Normal" Path="Images/ComponentFrame@2x.png" Plist="" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="SpeedComponent" ActionTag="885417409" Tag="47" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentWidthEnabled="True" LeftMargin="624.0000" RightMargin="96.0000" TopMargin="326.0000" BottomMargin="64.0000" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" Scale9Enable="True" LeftEage="8" RightEage="8" TopEage="8" BottomEage="8" Scale9OriginX="8" Scale9OriginY="8" Scale9Width="84" Scale9Height="84" ctype="PanelObjectData">
            <Size X="240.0000" Y="250.0000" />
            <Children>
              <AbstractNodeData Name="SpeedLabel" ActionTag="-327143193" Tag="58" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="47.5000" RightMargin="47.5000" TopMargin="8.0000" BottomMargin="116.0000" LabelText="SPEED" ctype="TextBMFontObjectData">
                <Size X="145.0000" Y="56.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0000" Y="200.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.8000" />
                <PreSize X="0.1208" Y="0.3111" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Line" ActionTag="-2011889947" Tag="57" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="108.0000" RightMargin="108.0000" TopMargin="52.0000" BottomMargin="124.0000" ctype="SpriteObjectData">
                <Size X="24.0000" Y="4.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0000" Y="175.0000" />
                <Scale ScaleX="7.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.7000" />
                <PreSize X="0.1000" Y="0.0222" />
                <FileData Type="Normal" Path="Images/Line@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="SpeedLevelLabel" ActionTag="-1679348087" Tag="28" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="99.0000" RightMargin="99.0000" TopMargin="58.5000" BottomMargin="40.5000" LabelText="0" ctype="TextBMFontObjectData">
                <Size X="42.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0000" Y="112.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.4500" />
                <PreSize X="0.1750" Y="0.3375" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo70.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="SpeedLevelUpButton" ActionTag="-119715907" Tag="22" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" TopMargin="177.0000" BottomMargin="-23.0000" TouchEnable="True" FontSize="16" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="210" Scale9Height="74" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="240.0000" Y="96.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0000" Y="25.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.1000" />
                <PreSize X="0.2500" Y="0.1500" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Images/LevelUpButtonPushed@2x.png" Plist="" />
                <NormalFileData Type="Normal" Path="Images/LevelUpButtonNormal@2x.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="1.0000" />
            <Position X="864.0000" Y="64.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9000" Y="0.1000" />
            <PreSize X="0.2500" Y="0.3906" />
            <FileData Type="Normal" Path="Images/ComponentFrame@2x.png" Plist="" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="CoinComponent" ActionTag="-47544359" Tag="50" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentWidthEnabled="True" LeftMargin="625.4077" RightMargin="94.5923" TopMargin="102.0000" BottomMargin="358.0000" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" Scale9Enable="True" LeftEage="8" RightEage="8" TopEage="8" BottomEage="8" Scale9OriginX="8" Scale9OriginY="8" Scale9Width="84" Scale9Height="84" ctype="PanelObjectData">
            <Size X="240.0000" Y="180.0000" />
            <Children>
              <AbstractNodeData Name="CoinLabel" ActionTag="2047377100" Tag="59" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="47.5001" RightMargin="47.4999" TopMargin="18.8000" BottomMargin="105.2000" LabelText="COIN" ctype="TextBMFontObjectData">
                <Size X="116.0000" Y="56.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0001" Y="133.2000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.7400" />
                <PreSize X="0.1208" Y="0.3111" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Line" ActionTag="15791466" Tag="60" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="108.0000" RightMargin="108.0000" TopMargin="70.0000" BottomMargin="106.0000" ctype="SpriteObjectData">
                <Size X="24.0000" Y="4.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0000" Y="108.0000" />
                <Scale ScaleX="7.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.6000" />
                <PreSize X="0.1000" Y="0.0222" />
                <FileData Type="Normal" Path="Images/Line@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="CoinCountLabel" ActionTag="768869216" Tag="52" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="99.0000" RightMargin="99.0000" TopMargin="64.5000" BottomMargin="4.5000" LabelText="0" ctype="TextBMFontObjectData">
                <Size X="42.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0000" Y="54.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.3000" />
                <PreSize X="0.1750" Y="0.3375" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo70.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="1.0000" ScaleY="0.5000" />
            <Position X="865.4077" Y="448.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9015" Y="0.7000" />
            <PreSize X="0.2500" Y="0.2813" />
            <FileData Type="Normal" Path="Images/ComponentFrame@2x.png" Plist="" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="RankComponent" ActionTag="-2089685191" Tag="49" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentWidthEnabled="True" LeftMargin="96.0000" RightMargin="489.6000" TopMargin="102.0000" BottomMargin="358.0000" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" Scale9Enable="True" LeftEage="8" RightEage="8" TopEage="8" BottomEage="8" Scale9OriginX="8" Scale9OriginY="8" Scale9Width="84" Scale9Height="84" ctype="PanelObjectData">
            <Size X="374.4000" Y="180.0000" />
            <Children>
              <AbstractNodeData Name="RankLabel" ActionTag="-895313029" Tag="62" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="118.4000" RightMargin="269.6000" TopMargin="18.8000" BottomMargin="105.2000" LabelText="RANK" ctype="TextBMFontObjectData">
                <Size X="116.0000" Y="56.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="131.0400" Y="133.2000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.3500" Y="0.7400" />
                <PreSize X="0.1208" Y="0.3111" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="Line" ActionTag="-797799947" Tag="63" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="164.4000" RightMargin="315.6000" TopMargin="70.0000" BottomMargin="106.0000" ctype="SpriteObjectData">
                <Size X="24.0000" Y="4.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="131.0400" Y="108.0000" />
                <Scale ScaleX="7.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.3500" Y="0.6000" />
                <PreSize X="0.1000" Y="0.0222" />
                <FileData Type="Normal" Path="Images/Line@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="RankUpButton" ActionTag="-105342212" Tag="61" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="312.0000" RightMargin="-120.0000" TopMargin="42.0000" BottomMargin="42.0000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="210" Scale9Height="74" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="240.0000" Y="96.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="374.4000" Y="90.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="1.0000" Y="0.5000" />
                <PreSize X="0.4762" Y="0.5333" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Images/RankUpButtonPushed@2x.png" Plist="" />
                <NormalFileData Type="Normal" Path="Images/RankUpButtonNormal@2x.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="RankLevelLabel" ActionTag="-2122385031" Tag="64" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="155.4000" RightMargin="306.6000" TopMargin="85.5000" BottomMargin="13.5000" LabelText="0" ctype="TextBMFontObjectData">
                <Size X="42.0000" Y="81.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="131.0400" Y="54.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.3500" Y="0.3000" />
                <PreSize X="0.1750" Y="0.3375" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo70.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleY="0.5000" />
            <Position X="96.0000" Y="448.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1000" Y="0.7000" />
            <PreSize X="0.3900" Y="0.2813" />
            <FileData Type="Normal" Path="Images/ComponentFrame@2x.png" Plist="" />
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