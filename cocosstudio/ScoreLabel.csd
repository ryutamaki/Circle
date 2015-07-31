<GameProjectFile>
  <PropertyGroup Type="Node" Name="ScoreLabel" ID="4837d213-e158-48fb-a1ae-d2be045d73bf" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="120" Speed="1.0000" ActivedAnimationName="CountUp">
        <Timeline ActionTag="-1925254411" Property="Position">
          <PointFrame FrameIndex="1" X="0.0000" Y="150.0000">
            <EasingData Type="27" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="0.0000" Y="0.0000">
            <EasingData Type="23" />
          </PointFrame>
          <PointFrame FrameIndex="50" X="0.0000" Y="0.0000">
            <EasingData Type="1" />
          </PointFrame>
          <PointFrame FrameIndex="55" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="90" X="0.0000" Y="0.0000">
            <EasingData Type="27" />
          </PointFrame>
          <PointFrame FrameIndex="120" X="0.0000" Y="150.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1925254411" Property="Scale">
          <ScaleFrame FrameIndex="1" X="1.0000" Y="1.0000">
            <EasingData Type="27" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="1.0000" Y="1.0000">
            <EasingData Type="23" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="45" X="1.0000" Y="1.0000">
            <EasingData Type="2" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="50" X="1.5000" Y="1.5000">
            <EasingData Type="1" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="55" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="81" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1925254411" Property="FrameEvent">
          <EventFrame FrameIndex="50" Tween="False" Value="CountUp" />
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="CountUp" StartIndex="0" EndIndex="121">
          <RenderColor A="255" R="0" G="0" B="139" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="ScoreLabel" Tag="51" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="ScoreLabel" ActionTag="-1925254411" Tag="52" IconVisible="False" LeftMargin="-21.0000" RightMargin="-21.0000" TopMargin="-190.5000" BottomMargin="109.5000" LabelText="0" ctype="TextBMFontObjectData">
            <Size X="42.0000" Y="81.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="150.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo70.fnt" Plist="" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>