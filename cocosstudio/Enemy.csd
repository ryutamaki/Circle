<GameProjectFile>
  <PropertyGroup Type="Node" Name="Enemy" ID="8590d622-a871-41c1-ba55-fafd14948388" Version="2.3.0.1" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="60" Speed="1.0000" ActivedAnimationName="Attack">
        <Timeline ActionTag="-2083801574" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="29" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="2.0000" Y="2.0000">
            <EasingData Type="2" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-2083801574" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="29" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="720.0000" Y="720.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-2083801574" Property="FrameEvent">
          <EventFrame FrameIndex="0" Tween="False" Value="Ready" />
          <EventFrame FrameIndex="30" Tween="False" Value="Attack" />
          <EventFrame FrameIndex="59" Tween="False" Value="Cooldown" />
          <EventFrame FrameIndex="60" Tween="False" Value="Finish" />
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Attack" StartIndex="0" EndIndex="61">
          <RenderColor A="150" R="250" G="128" B="114" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Enemy" Tag="3" ctype="GameNodeObjectData">
        <Size />
        <Children>
          <AbstractNodeData Name="Body" ActionTag="-2083801574" Tag="4" FrameEvent="Ready" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-50.0000" RightMargin="-50.0000" TopMargin="-50.0000" BottomMargin="-50.0000" ctype="SpriteObjectData">
            <Size X="100.0000" Y="100.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="Assets/Images/Enemy.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>