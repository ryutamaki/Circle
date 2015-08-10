<GameProjectFile>
  <PropertyGroup Type="Node" Name="Triangle" ID="8590d622-a871-41c1-ba55-fafd14948388" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="130" Speed="1.0000" ActivedAnimationName="Charge">
        <Timeline ActionTag="-2083801574" Property="VisibleForFrame">
          <BoolFrame FrameIndex="1" Tween="False" Value="True" />
          <BoolFrame FrameIndex="2" Tween="False" Value="False" />
          <BoolFrame FrameIndex="4" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="-2083801574" Property="Position">
          <PointFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="11" X="0.0000" Y="0.0000">
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
          <PointFrame FrameIndex="101" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="102" X="4.0000" Y="3.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="103" X="-5.0000" Y="-2.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="104" X="3.0000" Y="-3.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="105" X="-4.0000" Y="5.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="121" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="130" X="-30.0000" Y="0.0000">
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
        <AnimationInfo Name="Charge" StartIndex="100" EndIndex="106">
          <RenderColor A="150" R="123" G="104" B="238" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Triangle" Tag="3" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Body" ActionTag="-2083801574" Tag="4" IconVisible="False" LeftMargin="-40.0000" RightMargin="-40.0000" TopMargin="-40.0000" BottomMargin="-40.0000" ctype="SpriteObjectData">
            <Size X="80.0000" Y="80.0000" />
            <Children>
              <AbstractNodeData Name="Eyes" ActionTag="-598274595" Tag="26" IconVisible="False" LeftMargin="44.0000" RightMargin="28.0000" TopMargin="28.0000" BottomMargin="28.0000" ctype="SpriteObjectData">
                <Size X="8.0000" Y="24.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="48.0000" Y="40.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.6000" Y="0.5000" />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="Normal" Path="Images/TriangleEyes@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Images/TriangleBody@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>