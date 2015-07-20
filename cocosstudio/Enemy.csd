<GameProjectFile>
  <PropertyGroup Type="Node" Name="Enemy" ID="8590d622-a871-41c1-ba55-fafd14948388" Version="2.3.0.1" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="4" Speed="1.0000" ActivedAnimationName="Damaged">
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
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Damaged" StartIndex="0" EndIndex="5">
          <RenderColor A="150" R="255" G="160" B="122" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Enemy" Tag="3" ctype="GameNodeObjectData">
        <Size />
        <Children>
          <AbstractNodeData Name="Body" ActionTag="-2083801574" Tag="4" Rotation="720.0000" RotationSkewX="720.0000" RotationSkewY="720.0000" IconVisible="False" LeftMargin="-40.0000" RightMargin="-40.0000" TopMargin="-40.0000" BottomMargin="-40.0000" ctype="SpriteObjectData">
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
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>