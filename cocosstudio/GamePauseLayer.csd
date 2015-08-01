<GameProjectFile>
  <PropertyGroup Type="Layer" Name="GamePauseLayer" ID="d92b263c-6160-4c9a-802b-bc94d9a899ab" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Layer" CustomClassName="GamePauseLayer" Tag="32" ctype="GameLayerObjectData">
        <Size X="1334.0000" Y="750.0000" />
        <Children>
          <AbstractNodeData Name="Overlay" ActionTag="-1478764077" Tag="33" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" ctype="SpriteObjectData">
            <Size X="1334.0000" Y="750.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="667.0000" Y="375.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="Images/Overlay@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="PauseLayout" ActionTag="844789466" Tag="36" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="467.0000" RightMargin="467.0000" TopMargin="225.0000" BottomMargin="225.0000" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" Scale9Enable="True" LeftEage="33" RightEage="33" TopEage="33" BottomEage="33" Scale9OriginX="33" Scale9OriginY="33" Scale9Width="34" Scale9Height="34" ctype="PanelObjectData">
            <Size X="400.0000" Y="300.0000" />
            <Children>
              <AbstractNodeData Name="PauseLabel" ActionTag="-1192967496" Tag="37" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="127.5000" RightMargin="127.5000" TopMargin="47.0000" BottomMargin="197.0000" LabelText="PAUSE" ctype="TextBMFontObjectData">
                <Size X="145.0000" Y="56.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="200.0000" Y="225.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.7500" />
                <PreSize X="0.3625" Y="0.1867" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="QuitButton" ActionTag="1915915385" Tag="38" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="70.0000" RightMargin="230.0000" TopMargin="141.0000" BottomMargin="51.0000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="70" Scale9Height="86" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="100.0000" Y="108.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="120.0000" Y="105.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.3000" Y="0.3500" />
                <PreSize X="0.2500" Y="0.3600" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Images/RedQuitButtonPushed@2x.png" Plist="" />
                <NormalFileData Type="Normal" Path="Images/RedQuitButtonNormal@2x.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="ResumeButton" ActionTag="-849055338" Tag="39" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="230.0000" RightMargin="70.0000" TopMargin="141.0000" BottomMargin="51.0000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="70" Scale9Height="86" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="100.0000" Y="108.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="280.0000" Y="105.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.7000" Y="0.3500" />
                <PreSize X="0.2500" Y="0.3600" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Images/ResumeButtonPushed@2x.png" Plist="" />
                <NormalFileData Type="Normal" Path="Images/ResumeButtonNormal@2x.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="667.0000" Y="375.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.2999" Y="0.4000" />
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