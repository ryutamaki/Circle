<GameProjectFile>
  <PropertyGroup Type="Scene" Name="GameScene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Background" CanEdit="False" ActionTag="-351322501" Tag="23" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-187.0000" RightMargin="-187.0000" TopMargin="-110.0000" TouchEnable="True" BackColorAlpha="102" ComboBoxIndex="1" ColorAngle="90.0000" Scale9Width="1334" Scale9Height="750" ctype="PanelObjectData">
            <Size X="1334.0000" Y="750.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position X="480.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" />
            <PreSize X="1.3896" Y="1.1719" />
            <FileData Type="Normal" Path="Images/Background@2x.png" Plist="" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="Field" ActionTag="-1430883737" Tag="86" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-187.0000" RightMargin="-187.0000" TopMargin="-55.0000" BottomMargin="-55.0000" ctype="SpriteObjectData">
            <Size X="1334.0000" Y="750.0000" />
            <Children>
              <AbstractNodeData Name="ScoreLabel" ActionTag="-1096191250" Tag="59" IconVisible="True" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="667.0000" RightMargin="667.0000" TopMargin="75.0000" BottomMargin="675.0000" InnerActionSpeed="1.0000" ctype="ProjectNodeObjectData">
                <Size X="0.0000" Y="0.0000" />
                <AnchorPoint />
                <Position X="667.0000" Y="675.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.9000" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="ScoreLabel.csd" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="PauseButton" ActionTag="-875399286" Tag="25" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="40.0200" RightMargin="1249.9800" TopMargin="37.5000" BottomMargin="668.5000" TouchEnable="True" FontSize="14" LeftEage="14" RightEage="14" TopEage="11" BottomEage="11" Scale9OriginX="14" Scale9OriginY="11" Scale9Width="16" Scale9Height="22" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="44.0000" Y="44.0000" />
                <AnchorPoint ScaleY="1.0000" />
                <Position X="40.0200" Y="712.5000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.0300" Y="0.9500" />
                <PreSize X="0.0458" Y="0.0688" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Images/PauseButtonPushed@2x.png" Plist="" />
                <NormalFileData Type="Normal" Path="Images/PauseButtonNormal@2x.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.8451" Y="0.8344" />
            <FileData Type="Normal" Path="Images/Field@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="LobbyButton" Visible="False" ActionTag="-439445008" Tag="159" Alpha="102" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-187.0000" RightMargin="-187.0000" TopMargin="-55.0000" BottomMargin="-55.0000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="1304" Scale9Height="728" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="1334.0000" Y="750.0000" />
            <Children>
              <AbstractNodeData Name="StartLabel" ActionTag="-1593256057" Tag="44" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="493.0000" RightMargin="493.0000" TopMargin="347.0000" BottomMargin="347.0000" LabelText="TAP TO START" ctype="TextBMFontObjectData">
                <Size X="348.0000" Y="56.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="667.0000" Y="375.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.2609" Y="0.0747" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.3896" Y="1.1719" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="Images/Overlay@2x.png" Plist="" />
            <NormalFileData Type="Normal" Path="Images/Overlay@2x.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>