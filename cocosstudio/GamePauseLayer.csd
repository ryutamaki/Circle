<GameProjectFile>
  <PropertyGroup Type="Layer" Name="GamePauseLayer" ID="d92b263c-6160-4c9a-802b-bc94d9a899ab" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="90" Speed="1.0000" ActivedAnimationName="Show">
        <Timeline ActionTag="-1478764077" Property="Alpha">
          <IntFrame FrameIndex="1" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="20" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="70" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="90" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-1478764077" Property="CColor">
          <ColorFrame FrameIndex="1" Alpha="255">
            <EasingData Type="0" />
            <Color A="255" R="255" G="255" B="255" />
          </ColorFrame>
        </Timeline>
        <Timeline ActionTag="844789466" Property="Position">
          <PointFrame FrameIndex="1" X="667.0000" Y="974.9999">
            <EasingData Type="27" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="667.0000" Y="375.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="51" X="667.0000" Y="375.0000">
            <EasingData Type="27" />
          </PointFrame>
          <PointFrame FrameIndex="90" X="667.0000" Y="-225.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="844789466" Property="RotationSkew">
          <ScaleFrame FrameIndex="51" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="90" X="-20.0000" Y="-20.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Show" StartIndex="0" EndIndex="41">
          <RenderColor A="255" R="127" G="255" B="212" />
        </AnimationInfo>
        <AnimationInfo Name="Hide" StartIndex="50" EndIndex="91">
          <RenderColor A="255" R="255" G="255" B="0" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Layer" CustomClassName="GamePauseLayer" Tag="32" ctype="GameLayerObjectData">
        <Size X="1334.0000" Y="750.0000" />
        <Children>
          <AbstractNodeData Name="Overlay" ActionTag="-1478764077" Tag="33" Alpha="0" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" ctype="SpriteObjectData">
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
          <AbstractNodeData Name="PauseLayout" ActionTag="844789466" Tag="36" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="467.0000" RightMargin="467.0000" TopMargin="-374.9999" BottomMargin="824.9999" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" Scale9Enable="True" LeftEage="33" RightEage="33" TopEage="33" BottomEage="33" Scale9OriginX="33" Scale9OriginY="33" Scale9Width="34" Scale9Height="34" ctype="PanelObjectData">
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
            <Position X="667.0000" Y="974.9999" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="1.3000" />
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