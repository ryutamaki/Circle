<GameProjectFile>
  <PropertyGroup Type="Layer" Name="TutorialLayer" ID="a96de658-4795-43ea-9a84-5c46cff1993d" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="90" Speed="1.0000" ActivedAnimationName="Show">
        <Timeline ActionTag="-146086837" Property="Alpha">
          <IntFrame FrameIndex="1" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="20" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="75" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="90" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="480775543" Property="Position">
          <PointFrame FrameIndex="1" X="667.0000" Y="1050.0000">
            <EasingData Type="27" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="667.0000" Y="375.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="51" X="667.0000" Y="375.0000">
            <EasingData Type="27" />
          </PointFrame>
          <PointFrame FrameIndex="90" X="667.0000" Y="-375.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="480775543" Property="RotationSkew">
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
          <RenderColor A="150" R="255" G="0" B="0" />
        </AnimationInfo>
        <AnimationInfo Name="Hide" StartIndex="50" EndIndex="91">
          <RenderColor A="150" R="240" G="128" B="128" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Layer" CustomClassName="TutorialLayer" Tag="54" ctype="GameLayerObjectData">
        <Size X="1334.0000" Y="750.0000" />
        <Children>
          <AbstractNodeData Name="Overlay" ActionTag="-146086837" Tag="74" Alpha="0" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="1304" Scale9Height="728" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="1334.0000" Y="750.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="667.0000" Y="375.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="Images/Overlay@2x.png" Plist="" />
            <NormalFileData Type="Normal" Path="Images/Overlay@2x.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="TutorialLayout" ActionTag="480775543" Tag="71" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="267.0000" RightMargin="267.0000" TopMargin="-540.0000" BottomMargin="810.0000" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" Scale9Enable="True" LeftEage="33" RightEage="33" TopEage="33" BottomEage="33" Scale9OriginX="33" Scale9OriginY="33" Scale9Width="34" Scale9Height="34" ctype="PanelObjectData">
            <Size X="800.0000" Y="480.0000" />
            <Children>
              <AbstractNodeData Name="Basic" ActionTag="-405391995" Tag="73" VisibleForFrame="False" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="57.0000" RightMargin="57.0000" TopMargin="55.0000" BottomMargin="55.0000" ctype="SpriteObjectData">
                <Size X="686.0000" Y="370.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="400.0000" Y="240.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.8575" Y="0.7708" />
                <FileData Type="Normal" Path="Images/TutorialBasic@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="667.0000" Y="1050.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="1.4000" />
            <PreSize X="0.5997" Y="0.6400" />
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