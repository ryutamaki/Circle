<GameProjectFile>
  <PropertyGroup Type="Node" Name="Coin" ID="8f1d1515-aacf-4dde-b6ac-4bfc4cc68c15" Version="2.3.1.1" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="59" Speed="1.0000" ActivedAnimationName="Drop">
        <Timeline ActionTag="1592479325" Property="Position">
          <PointFrame FrameIndex="1" X="0.0000" Y="0.0000">
            <EasingData Type="10" />
          </PointFrame>
          <PointFrame FrameIndex="10" X="0.0000" Y="10.0000">
            <EasingData Type="4" />
          </PointFrame>
          <PointFrame FrameIndex="20" X="0.0000" Y="-10.0000">
            <EasingData Type="2" />
          </PointFrame>
          <PointFrame FrameIndex="30" X="0.0000" Y="0.0000">
            <EasingData Type="4" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="0.0000" Y="-20.0000">
            <EasingData Type="2" />
          </PointFrame>
          <PointFrame FrameIndex="50" X="0.0000" Y="-10.0000">
            <EasingData Type="4" />
          </PointFrame>
          <PointFrame FrameIndex="59" X="0.0000" Y="-30.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Drop" StartIndex="0" EndIndex="60">
          <RenderColor A="150" R="147" G="112" B="219" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Node" CustomClassName="Coin" Tag="18" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="Coin" ActionTag="1592479325" Tag="19" IconVisible="False" LeftMargin="-30.0000" RightMargin="-30.0000" BottomMargin="-60.0000" ctype="SpriteObjectData">
            <Size X="60.0000" Y="60.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position Y="-30.0000" />
            <Scale ScaleX="0.5000" ScaleY="0.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="Normal" Path="Images/Coin@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>