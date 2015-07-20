<GameProjectFile>
  <PropertyGroup Type="Node" Name="Character" ID="11748200-112a-45c6-a796-472168a2b2dd" Version="2.3.0.1" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="10" Speed="1.0000" ActivedAnimationName="Attack">
        <Timeline ActionTag="-1773017991" Property="FrameEvent">
          <EventFrame FrameIndex="1" Tween="False" Value="Ready" />
          <EventFrame FrameIndex="2" Tween="False" Value="Attack" />
          <EventFrame FrameIndex="5" Tween="False" Value="Cooldown" />
          <EventFrame FrameIndex="10" Tween="False" Value="Finish" />
        </Timeline>
        <Timeline ActionTag="-1773017991" Property="Position">
          <PointFrame FrameIndex="1" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="2" X="80.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="5" X="80.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="10" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Attack" StartIndex="0" EndIndex="11">
          <RenderColor A="255" R="230" G="230" B="250" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Character" Tag="8" ctype="GameNodeObjectData">
        <Size />
        <Children>
          <AbstractNodeData Name="Body" ActionTag="-1773017991" Tag="62" IconVisible="False" LeftMargin="-40.0000" RightMargin="-40.0000" TopMargin="-40.0000" BottomMargin="-40.0000" ctype="SpriteObjectData">
            <Size X="80.0000" Y="80.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="Assets/Images/Resources-2x/GreenRobot@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>