<GameProjectFile>
  <PropertyGroup Type="Node" Name="Circle" ID="11748200-112a-45c6-a796-472168a2b2dd" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="199" Speed="1.0000" ActivedAnimationName="Charging">
        <Timeline ActionTag="629999460" Property="Scale">
          <ScaleFrame FrameIndex="31" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="61" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="70" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="99" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="629999460" Property="VisibleForFrame">
          <BoolFrame FrameIndex="1" Tween="False" Value="False" />
          <BoolFrame FrameIndex="11" Tween="False" Value="False" />
          <BoolFrame FrameIndex="20" Tween="False" Value="False" />
          <BoolFrame FrameIndex="31" Tween="False" Value="True" />
          <BoolFrame FrameIndex="100" Tween="False" Value="False" />
        </Timeline>
        <Timeline ActionTag="-1773017991" Property="FrameEvent">
          <EventFrame FrameIndex="11" Tween="False" Value="Ready" />
          <EventFrame FrameIndex="12" Tween="False" Value="Attack" />
          <EventFrame FrameIndex="19" Tween="False" Value="Cooldown" />
          <EventFrame FrameIndex="20" Tween="False" Value="Finish" />
          <EventFrame FrameIndex="31" Tween="False" Value="Ready" />
          <EventFrame FrameIndex="61" Tween="False" Value="Attack" />
          <EventFrame FrameIndex="71" Tween="False" Value="Cooldown" />
          <EventFrame FrameIndex="100" Tween="False" Value="Finish" />
          <EventFrame FrameIndex="121" Tween="False" Value="Ready" />
          <EventFrame FrameIndex="122" Tween="False" Value="Attack" />
          <EventFrame FrameIndex="198" Tween="False" Value="Cooldown" />
          <EventFrame FrameIndex="199" Tween="False" Value="Finish" />
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
          <PointFrame FrameIndex="108" X="2.0000" Y="2.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="110" X="2.0000" Y="-2.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="112" X="-1.0000" Y="-1.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1773017991" Property="VisibleForFrame">
          <BoolFrame FrameIndex="1" Tween="False" Value="True" />
          <BoolFrame FrameIndex="2" Tween="False" Value="False" />
          <BoolFrame FrameIndex="3" Tween="False" Value="True" />
          <BoolFrame FrameIndex="4" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="-1773017991" Property="Scale">
          <ScaleFrame FrameIndex="31" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="0.8000" Y="0.8000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="61" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="70" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="99" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="106" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="114" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="121" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="122" X="2.5000" Y="2.5000">
            <EasingData Type="29" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="198" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Attack" StartIndex="10" EndIndex="21">
          <RenderColor A="255" R="230" G="230" B="250" />
        </AnimationInfo>
        <AnimationInfo Name="Damaged" StartIndex="0" EndIndex="5">
          <RenderColor A="255" R="255" G="239" B="213" />
        </AnimationInfo>
        <AnimationInfo Name="AttackNeedle" StartIndex="30" EndIndex="101">
          <RenderColor A="255" R="233" G="150" B="122" />
        </AnimationInfo>
        <AnimationInfo Name="ChargeAttack" StartIndex="120" EndIndex="200">
          <RenderColor A="150" R="240" G="248" B="255" />
        </AnimationInfo>
        <AnimationInfo Name="Charging" StartIndex="105" EndIndex="116">
          <RenderColor A="150" R="128" G="128" B="128" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Circle" Tag="8" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Needle" ActionTag="629999460" Tag="49" VisibleForFrame="False" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-78.0000" RightMargin="-78.0000" TopMargin="-78.0000" BottomMargin="-78.0000" ctype="SpriteObjectData">
            <Size X="156.0000" Y="156.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="0.5000" ScaleY="0.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="1.9500" Y="1.9500" />
            <FileData Type="Normal" Path="Images/CircleNeedle@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="Body" ActionTag="-1773017991" Tag="62" IconVisible="False" LeftMargin="-40.0000" RightMargin="-40.0000" TopMargin="-40.0000" BottomMargin="-40.0000" ctype="SpriteObjectData">
            <Size X="80.0000" Y="80.0000" />
            <Children>
              <AbstractNodeData Name="Eyes" ActionTag="-758022569" Tag="21" IconVisible="False" PositionPercentYEnabled="True" LeftMargin="58.8608" RightMargin="13.1392" TopMargin="24.0000" BottomMargin="24.0000" ctype="SpriteObjectData">
                <Size X="8.0000" Y="32.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="62.8608" Y="40.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.7858" Y="0.5000" />
                <PreSize X="0.1000" Y="0.4000" />
                <FileData Type="Normal" Path="Images/CircleEyes@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Images/CircleBody@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>