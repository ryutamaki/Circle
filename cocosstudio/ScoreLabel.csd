<GameProjectFile>
  <PropertyGroup Type="Node" Name="ScoreLabel" ID="4837d213-e158-48fb-a1ae-d2be045d73bf" Version="2.3.1.1" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="180" Speed="1.0000" ActivedAnimationName="Appear">
        <Timeline ActionTag="-1925254411" Property="Position">
          <PointFrame FrameIndex="1" X="0.0000" Y="150.0000">
            <EasingData Type="29" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="51" X="0.0000" Y="0.0000">
            <EasingData Type="27" />
          </PointFrame>
          <PointFrame FrameIndex="81" X="0.0000" Y="150.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1925254411" Property="Scale">
          <ScaleFrame FrameIndex="101" X="1.0000" Y="1.0000">
            <EasingData Type="26" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="115" X="1.5000" Y="1.5000">
            <EasingData Type="1" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="175" X="1.5000" Y="1.5000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="180" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1925254411" Property="RotationSkew">
          <ScaleFrame FrameIndex="180" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1925254411" Property="FrameEvent">
          <EventFrame FrameIndex="115" Tween="False" Value="Fire" />
          <EventFrame FrameIndex="180" Tween="False" Value="End" />
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Appear" StartIndex="0" EndIndex="31">
          <RenderColor A="150" R="0" G="0" B="139" />
        </AnimationInfo>
        <AnimationInfo Name="Disappear" StartIndex="50" EndIndex="81">
          <RenderColor A="150" R="0" G="100" B="0" />
        </AnimationInfo>
        <AnimationInfo Name="Change" StartIndex="100" EndIndex="181">
          <RenderColor A="150" R="255" G="218" B="185" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="ScoreLabel" Tag="51" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="ScoreLabel" ActionTag="-1925254411" Tag="52" IconVisible="False" LeftMargin="-21.0000" RightMargin="-21.0000" TopMargin="-40.5000" BottomMargin="-40.5000" LabelText="0" ctype="TextBMFontObjectData">
            <Size X="42.0000" Y="81.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
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