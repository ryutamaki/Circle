<GameProjectFile>
  <PropertyGroup Type="Node" Name="Character" ID="11748200-112a-45c6-a796-472168a2b2dd" Version="2.3.1.1" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="20" Speed="1.0000" ActivedAnimationName="Damaged">
        <Timeline ActionTag="-1773017991" Property="FrameEvent">
          <EventFrame FrameIndex="11" Tween="False" Value="Ready" />
          <EventFrame FrameIndex="12" Tween="False" Value="Attack" />
          <EventFrame FrameIndex="19" Tween="False" Value="Cooldown" />
          <EventFrame FrameIndex="20" Tween="False" Value="Finish" />
        </Timeline>
        <Timeline ActionTag="-1773017991" Property="Position">
          <PointFrame FrameIndex="11" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="12" X="80.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="19" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="20" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1773017991" Property="VisibleForFrame">
          <BoolFrame FrameIndex="1" Tween="False" Value="True" />
          <BoolFrame FrameIndex="2" Tween="False" Value="False" />
          <BoolFrame FrameIndex="3" Tween="False" Value="True" />
          <BoolFrame FrameIndex="4" Tween="False" Value="True" />
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Attack" StartIndex="10" EndIndex="21">
          <RenderColor A="255" R="230" G="230" B="250" />
        </AnimationInfo>
        <AnimationInfo Name="Damaged" StartIndex="0" EndIndex="5">
          <RenderColor A="255" R="255" G="239" B="213" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Character" Tag="8" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Body" ActionTag="-1773017991" Tag="62" IconVisible="False" LeftMargin="-40.0000" RightMargin="-40.0000" TopMargin="-40.0000" BottomMargin="-40.0000" ctype="SpriteObjectData">
            <Size X="80.0000" Y="80.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Images/Body@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Frame" ActionTag="-576101947" Tag="36" IconVisible="False" LeftMargin="-40.0000" RightMargin="-40.0000" TopMargin="-55.0000" BottomMargin="45.0000" ctype="SpriteObjectData">
            <Size X="80.0000" Y="10.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="50.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Images/Frame@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Bar" ActionTag="-1882435512" Tag="35" IconVisible="False" LeftMargin="-38.0000" RightMargin="-38.0000" TopMargin="-53.0000" BottomMargin="47.0000" ctype="SpriteObjectData">
            <Size X="76.0000" Y="6.0000" />
            <AnchorPoint ScaleY="0.5000" />
            <Position X="-38.0000" Y="50.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Images/Bar@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>