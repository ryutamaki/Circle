<GameProjectFile>
  <PropertyGroup Type="Scene" Name="PowerUpScene" ID="dcbabf22-44d5-46ba-abfc-4ccf1ccb552a" Version="2.3.1.1" />
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
          <AbstractNodeData Name="Field" ActionTag="1241435557" Tag="14" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-187.0000" RightMargin="-187.0000" TopMargin="-55.0000" BottomMargin="-55.0000" ctype="SpriteObjectData">
            <Size X="1334.0000" Y="750.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="Images/Field@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="PowerUpLabel" ActionTag="-268652109" Tag="15" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="392.0000" RightMargin="392.0000" TopMargin="43.0000" BottomMargin="555.0000" LabelText="POWER UP" ctype="TextBMFontObjectData">
            <Size X="176.0000" Y="42.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="576.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.9000" />
            <PreSize X="0.1833" Y="0.0656" />
            <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo36.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="HpButton" ActionTag="236778797" Tag="21" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="190.0000" RightMargin="670.0000" TopMargin="398.0000" BottomMargin="142.0000" TouchEnable="True" FontSize="16" ButtonText="HP" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="100.0000" Y="100.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="240.0000" Y="192.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.2500" Y="0.3000" />
            <PreSize X="0.1042" Y="0.1563" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
            <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="SpeedButton" ActionTag="-119715907" Tag="22" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="670.0000" RightMargin="190.0000" TopMargin="398.0000" BottomMargin="142.0000" TouchEnable="True" FontSize="16" ButtonText="SPEED" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="100.0000" Y="100.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="720.0000" Y="192.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7500" Y="0.3000" />
            <PreSize X="0.1042" Y="0.1563" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
            <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="AttackButton" ActionTag="639465357" Tag="23" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="430.0000" RightMargin="430.0000" TopMargin="398.0000" BottomMargin="142.0000" TouchEnable="True" FontSize="16" ButtonText="ATTACK" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="100.0000" Y="100.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="192.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.3000" />
            <PreSize X="0.1042" Y="0.1563" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
            <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="HpLabel" ActionTag="1384261388" Tag="26" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="229.0000" RightMargin="709.0000" TopMargin="299.0000" BottomMargin="299.0000" LabelText="0" ctype="TextBMFontObjectData">
            <Size X="22.0000" Y="42.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="240.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.2500" Y="0.5000" />
            <PreSize X="0.0229" Y="0.0656" />
            <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo36.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="AttackLabel" ActionTag="-1502864414" Tag="27" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="469.0000" RightMargin="469.0000" TopMargin="299.0000" BottomMargin="299.0000" LabelText="0" ctype="TextBMFontObjectData">
            <Size X="22.0000" Y="42.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.0229" Y="0.0656" />
            <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo36.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="SpeedLabel" ActionTag="-1679348087" Tag="28" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="709.0000" RightMargin="229.0000" TopMargin="299.0000" BottomMargin="299.0000" LabelText="0" ctype="TextBMFontObjectData">
            <Size X="22.0000" Y="42.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="720.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7500" Y="0.5000" />
            <PreSize X="0.0229" Y="0.0656" />
            <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo36.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="BackButton" ActionTag="283203610" Tag="29" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="46.0000" RightMargin="814.0000" TopMargin="39.0000" BottomMargin="551.0000" TouchEnable="True" FontSize="14" ButtonText="Back" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="16" Scale9Height="14" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="100.0000" Y="50.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="96.0000" Y="576.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1000" Y="0.9000" />
            <PreSize X="0.1042" Y="0.0781" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Default" Path="Default/Button_Press.png" Plist="" />
            <NormalFileData Type="Default" Path="Default/Button_Normal.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="CoinCountLabel" ActionTag="-475334453" Tag="30" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="326.0000" RightMargin="326.0000" TopMargin="171.0000" BottomMargin="427.0000" LabelText="0" ctype="TextBMFontObjectData">
            <Size X="22.0000" Y="42.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="448.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.7000" />
            <PreSize X="0.3208" Y="0.0656" />
            <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo36.fnt" Plist="" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>