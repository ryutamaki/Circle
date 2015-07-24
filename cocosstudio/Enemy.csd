<GameProjectFile>
  <PropertyGroup Type="Node" Name="Enemy" ID="8590d622-a871-41c1-ba55-fafd14948388" Version="2.3.1.1" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="90" Speed="1.0000" ActivedAnimationName="Attack">
        <Timeline ActionTag="1003481947" Property="Scale">
          <ScaleFrame FrameIndex="10" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="11" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="49" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="50" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="85" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1003481947" Property="FrameEvent">
          <EventFrame FrameIndex="11" Tween="False" Value="Ready" />
          <EventFrame FrameIndex="50" Tween="False" Value="Attack" />
          <EventFrame FrameIndex="55" Tween="False" Value="Cooldown" />
          <EventFrame FrameIndex="85" Tween="False" Value="" />
          <EventFrame FrameIndex="90" Tween="False" Value="Finish" />
        </Timeline>
        <Timeline ActionTag="-2083801574" Property="Scale">
          <ScaleFrame FrameIndex="10" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="11" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="49" X="0.8000" Y="0.8000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="50" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
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
          <RenderColor A="255" R="255" G="160" B="122" />
        </AnimationInfo>
        <AnimationInfo Name="Attack" StartIndex="10" EndIndex="91">
          <RenderColor A="255" R="219" G="112" B="147" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Enemy" Tag="3" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Needle" ActionTag="1003481947" Tag="86" IconVisible="False" LeftMargin="-78.0000" RightMargin="-78.0000" TopMargin="-78.0000" BottomMargin="-78.0000" ctype="SpriteObjectData">
            <Size X="156.0000" Y="156.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="0.5000" ScaleY="0.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Images/Needle@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Body" ActionTag="-2083801574" Tag="4" IconVisible="False" LeftMargin="-40.0000" RightMargin="-40.0000" TopMargin="-40.0000" BottomMargin="-40.0000" ctype="SpriteObjectData">
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
          <AbstractNodeData Name="Frame" ActionTag="839447432" Tag="41" IconVisible="False" LeftMargin="-40.0000" RightMargin="-40.0000" TopMargin="-55.0000" BottomMargin="45.0000" ctype="SpriteObjectData">
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
          <AbstractNodeData Name="Bar" ActionTag="-450558746" Tag="42" IconVisible="False" LeftMargin="-38.0000" RightMargin="-38.0000" TopMargin="-53.0000" BottomMargin="47.0000" ctype="SpriteObjectData">
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