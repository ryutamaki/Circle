<GameProjectFile>
  <PropertyGroup Type="Node" Name="Enemy" ID="8590d622-a871-41c1-ba55-fafd14948388" Version="2.3.0.1" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="60" Speed="1.0000" ActivedAnimationName="Damaged">
        <Timeline ActionTag="-684589477" Property="Position">
          <PointFrame FrameIndex="11" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-684589477" Property="Scale">
          <ScaleFrame FrameIndex="11" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="37" X="0.8000" Y="0.8000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="40" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-2083801574" Property="Scale">
          <ScaleFrame FrameIndex="11" X="1.0000" Y="1.0000">
            <EasingData Type="1" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="37" X="1.5000" Y="1.5000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="40" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="55" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-2083801574" Property="RotationSkew">
          <ScaleFrame FrameIndex="11" X="0.0000" Y="0.0000">
            <EasingData Type="1" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-2083801574" Property="FrameEvent">
          <EventFrame FrameIndex="11" Tween="False" Value="Ready" />
          <EventFrame FrameIndex="41" Tween="False" Value="Attack" />
          <EventFrame FrameIndex="55" Tween="False" Value="Cooldown" />
          <EventFrame FrameIndex="60" Tween="False" Value="Finish" />
        </Timeline>
        <Timeline ActionTag="-2083801574" Property="Position">
          <PointFrame FrameIndex="11" X="0.0000" Y="0.0000">
            <EasingData Type="1" />
          </PointFrame>
          <PointFrame FrameIndex="37" X="0.0000" Y="200.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-2083801574" Property="CColor">
          <ColorFrame FrameIndex="1" Alpha="255">
            <EasingData Type="0" />
            <Color A="255" R="255" G="255" B="255" />
          </ColorFrame>
          <ColorFrame FrameIndex="2" Alpha="255">
            <EasingData Type="0" />
            <Color A="255" R="255" G="255" B="0" />
          </ColorFrame>
          <ColorFrame FrameIndex="3" Alpha="255">
            <EasingData Type="0" />
            <Color A="255" R="255" G="255" B="0" />
          </ColorFrame>
          <ColorFrame FrameIndex="4" Alpha="255">
            <EasingData Type="0" />
            <Color A="255" R="255" G="255" B="255" />
          </ColorFrame>
        </Timeline>
        <Timeline ActionTag="-2083801574" Property="VisibleForFrame">
          <BoolFrame FrameIndex="1" Tween="False" Value="True" />
          <BoolFrame FrameIndex="2" Tween="False" Value="False" />
          <BoolFrame FrameIndex="4" Tween="False" Value="True" />
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Damaged" StartIndex="0" EndIndex="5">
          <RenderColor A="150" R="255" G="160" B="122" />
        </AnimationInfo>
        <AnimationInfo Name="Attack" StartIndex="10" EndIndex="61">
          <RenderColor A="150" R="219" G="112" B="147" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Enemy" Tag="3" ctype="GameNodeObjectData">
        <Size />
        <Children>
          <AbstractNodeData Name="Shadow" ActionTag="-684589477" Tag="5" FrameEvent="Attack" IconVisible="False" LeftMargin="-40.0000" RightMargin="-40.0000" TopMargin="-40.0000" BottomMargin="-40.0000" ctype="SpriteObjectData">
            <Size X="80.0000" Y="80.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="Assets/Images/Resources-2x/Shadow@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Body" ActionTag="-2083801574" Tag="4" IconVisible="False" LeftMargin="-40.0000" RightMargin="-40.0000" TopMargin="-40.0000" BottomMargin="-40.0000" ctype="SpriteObjectData">
            <Size X="80.0000" Y="80.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="Assets/Images/Resources-2x/RedRobot@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Frame" ActionTag="839447432" Tag="41" IconVisible="False" LeftMargin="-40.0000" RightMargin="-40.0000" TopMargin="-60.0000" BottomMargin="40.0000" ctype="SpriteObjectData">
            <Size X="80.0000" Y="20.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="50.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="Assets/Images/Resources-2x/HpFrame@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Bar" ActionTag="-450558746" Tag="42" IconVisible="False" LeftMargin="-38.0000" RightMargin="-38.0000" TopMargin="-57.0000" BottomMargin="43.0000" ctype="SpriteObjectData">
            <Size X="76.0000" Y="14.0000" />
            <AnchorPoint ScaleY="0.5000" />
            <Position X="-38.0000" Y="50.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize />
            <FileData Type="Normal" Path="Assets/Images/Resources-2x/HpBar@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>