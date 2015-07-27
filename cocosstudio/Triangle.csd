<GameProjectFile>
  <PropertyGroup Type="Node" Name="Triangle" ID="8590d622-a871-41c1-ba55-fafd14948388" Version="2.3.1.1" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="70" Speed="1.0000" ActivedAnimationName="Attack">
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
        <Timeline ActionTag="-2083801574" Property="Position">
          <PointFrame FrameIndex="11" X="0.0000" Y="5.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="15" X="-2.0000" Y="5.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="20" X="-4.0000" Y="-5.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="25" X="-7.0000" Y="5.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="-11.0000" Y="-5.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="35" X="-15.0000" Y="5.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="39" X="-20.0000" Y="-5.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="-20.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="45" X="80.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="68" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-2083801574" Property="FrameEvent">
          <EventFrame FrameIndex="11" Tween="False" Value="Ready" />
          <EventFrame FrameIndex="40" Tween="False" Value="Attack" />
          <EventFrame FrameIndex="45" Tween="False" Value="Cooldown" />
          <EventFrame FrameIndex="70" Tween="False" Value="Finish" />
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Damaged" StartIndex="0" EndIndex="5">
          <RenderColor A="255" R="255" G="160" B="122" />
        </AnimationInfo>
        <AnimationInfo Name="Attack" StartIndex="10" EndIndex="71">
          <RenderColor A="255" R="219" G="112" B="147" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Triangle" Tag="3" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Body" ActionTag="-2083801574" Tag="4" IconVisible="False" LeftMargin="-40.0000" RightMargin="-40.0000" TopMargin="-45.0000" BottomMargin="-35.0000" ctype="SpriteObjectData">
            <Size X="80.0000" Y="80.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="5.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Images/TriangleBody@2x.png" Plist="" />
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