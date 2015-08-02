<GameProjectFile>
  <PropertyGroup Type="Layer" Name="GameResultLayer" ID="2f95d525-95aa-458f-b5d2-aedc89374641" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="91" Speed="1.0000">
        <Timeline ActionTag="-874100482" Property="Alpha">
          <IntFrame FrameIndex="1" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="20" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="70" Value="255">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="89" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="310833125" Property="Position">
          <PointFrame FrameIndex="10" X="667.0000" Y="1050.0000">
            <EasingData Type="27" />
          </PointFrame>
          <PointFrame FrameIndex="40" X="667.0000" Y="375.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="51" X="667.0000" Y="375.0000">
            <EasingData Type="27" />
          </PointFrame>
          <PointFrame FrameIndex="90" X="667.0000" Y="-375.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="91" X="667.0000" Y="-450.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="310833125" Property="RotationSkew">
          <ScaleFrame FrameIndex="51" X="0.0000" Y="0.0000">
            <EasingData Type="27" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="90" X="-20.0000" Y="-20.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="Show" StartIndex="0" EndIndex="41">
          <RenderColor A="255" R="255" G="228" B="181" />
        </AnimationInfo>
        <AnimationInfo Name="hide" StartIndex="50" EndIndex="91">
          <RenderColor A="255" R="253" G="245" B="230" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Layer" CustomClassName="GameResultLayer" Tag="40" ctype="GameLayerObjectData">
        <Size X="1334.0000" Y="750.0000" />
        <Children>
          <AbstractNodeData Name="Overlay" ActionTag="-874100482" Tag="12" Alpha="0" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" ctype="SpriteObjectData">
            <Size X="1334.0000" Y="750.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="667.0000" Y="375.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="Images/Overlay@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="ResultLayout" ActionTag="310833125" Tag="16" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="267.0000" RightMargin="267.0000" TopMargin="-540.0000" BottomMargin="810.0000" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" Scale9Enable="True" LeftEage="33" RightEage="33" TopEage="33" BottomEage="33" Scale9OriginX="33" Scale9OriginY="33" Scale9Width="34" Scale9Height="34" ctype="PanelObjectData">
            <Size X="800.0000" Y="480.0000" />
            <Children>
              <AbstractNodeData Name="ResultLabel" ActionTag="141361534" Tag="17" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="313.0000" RightMargin="313.0000" TopMargin="44.0000" BottomMargin="380.0000" LabelText="RESULT" ctype="TextBMFontObjectData">
                <Size X="174.0000" Y="56.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="400.0000" Y="408.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.8500" />
                <PreSize X="0.2175" Y="0.1167" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="RetryButton" ActionTag="-1597892410" Tag="15" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="470.0000" RightMargin="230.0000" TopMargin="330.0000" BottomMargin="42.0000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="70" Scale9Height="86" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="100.0000" Y="108.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="520.0000" Y="96.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.6500" Y="0.2000" />
                <PreSize X="0.1250" Y="0.2250" />
                <TextColor A="255" R="65" G="65" B="70" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Images/RetryButtonPushed@2x.png" Plist="" />
                <NormalFileData Type="Normal" Path="Images/RetryButtonNormal@2x.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="QuitButton" ActionTag="1148339486" Tag="42" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="230.0000" RightMargin="470.0000" TopMargin="330.0000" BottomMargin="42.0000" TouchEnable="True" FontSize="72" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="70" Scale9Height="86" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
                <Size X="100.0000" Y="108.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="280.0000" Y="96.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.3500" Y="0.2000" />
                <PreSize X="0.0750" Y="0.1440" />
                <TextColor A="255" R="230" G="230" B="250" />
                <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
                <PressedFileData Type="Normal" Path="Images/QuitButtonPushed@2x.png" Plist="" />
                <NormalFileData Type="Normal" Path="Images/QuitButtonNormal@2x.png" Plist="" />
                <OutlineColor A="255" R="255" G="0" B="0" />
                <ShadowColor A="255" R="110" G="110" B="110" />
              </AbstractNodeData>
              <AbstractNodeData Name="ScoreCountLabel" ActionTag="-1933879219" Tag="43" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="185.5000" RightMargin="585.5000" TopMargin="212.0000" BottomMargin="212.0000" LabelText="0" ctype="TextBMFontObjectData">
                <Size X="29.0000" Y="56.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="200.0000" Y="240.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2500" Y="0.5000" />
                <PreSize X="0.0362" Y="0.1167" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="HighScoreCountLabel" ActionTag="-877991394" Tag="14" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="385.5000" RightMargin="385.5000" TopMargin="212.0000" BottomMargin="212.0000" LabelText="0" ctype="TextBMFontObjectData">
                <Size X="29.0000" Y="56.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="400.0000" Y="240.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.5000" />
                <PreSize X="0.0362" Y="0.1167" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="CoinCountLabel" ActionTag="498758070" Tag="18" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="585.5000" RightMargin="185.5000" TopMargin="212.0000" BottomMargin="212.0000" LabelText="0" ctype="TextBMFontObjectData">
                <Size X="29.0000" Y="56.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="600.0000" Y="240.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.7500" Y="0.5000" />
                <PreSize X="0.2609" Y="0.0747" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="LineForScore" ActionTag="1993790325" Tag="19" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="188.0000" RightMargin="588.0000" TopMargin="190.0000" BottomMargin="286.0000" ctype="SpriteObjectData">
                <Size X="24.0000" Y="4.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="200.0000" Y="288.0000" />
                <Scale ScaleX="5.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2500" Y="0.6000" />
                <PreSize X="0.0300" Y="0.0083" />
                <FileData Type="Normal" Path="Images/Line@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="ScoreLabel" ActionTag="-1379223287" Tag="20" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="155.0000" RightMargin="555.0000" TopMargin="150.5000" BottomMargin="294.5000" LabelText="SCORE" ctype="TextBMFontObjectData">
                <Size X="90.0000" Y="35.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="200.0000" Y="312.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.2500" Y="0.6500" />
                <PreSize X="0.1125" Y="0.0729" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/CircleFont30.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="LineForBest" ActionTag="914425589" Tag="21" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="388.0000" RightMargin="388.0000" TopMargin="190.0000" BottomMargin="286.0000" ctype="SpriteObjectData">
                <Size X="24.0000" Y="4.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="400.0000" Y="288.0000" />
                <Scale ScaleX="5.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.6000" />
                <PreSize X="0.0300" Y="0.0083" />
                <FileData Type="Normal" Path="Images/Line@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="BestLabel" ActionTag="1255202195" Tag="22" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="364.0000" RightMargin="364.0000" TopMargin="150.5000" BottomMargin="294.5000" LabelText="BEST" ctype="TextBMFontObjectData">
                <Size X="72.0000" Y="35.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="400.0000" Y="312.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.6500" />
                <PreSize X="0.1125" Y="0.0729" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/CircleFont30.fnt" Plist="" />
              </AbstractNodeData>
              <AbstractNodeData Name="LineForCoin" ActionTag="1397708263" Tag="23" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="588.0000" RightMargin="188.0000" TopMargin="190.0000" BottomMargin="286.0000" ctype="SpriteObjectData">
                <Size X="24.0000" Y="4.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="600.0000" Y="288.0000" />
                <Scale ScaleX="5.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.7500" Y="0.6000" />
                <PreSize X="0.0300" Y="0.0083" />
                <FileData Type="Normal" Path="Images/Line@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="CoinLabel" ActionTag="-1665065820" Tag="24" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="564.0000" RightMargin="164.0000" TopMargin="150.5000" BottomMargin="294.5000" LabelText="COIN" ctype="TextBMFontObjectData">
                <Size X="72.0000" Y="35.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="600.0000" Y="312.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.7500" Y="0.6500" />
                <PreSize X="0.1125" Y="0.0729" />
                <LabelBMFontFile_CNB Type="Normal" Path="Fonts/CircleFont30.fnt" Plist="" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="667.0000" Y="1050.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="1.4000" />
            <PreSize X="0.5997" Y="0.6400" />
            <FileData Type="Normal" Path="Images/ComponentFrame@2x.png" Plist="" />
            <SingleColor A="255" R="150" G="200" B="255" />
            <FirstColor A="255" R="150" G="200" B="255" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>