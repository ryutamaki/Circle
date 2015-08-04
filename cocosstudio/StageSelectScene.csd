<GameProjectFile>
  <PropertyGroup Type="Scene" Name="StageSelectScene" ID="b393eeb7-20d2-40a2-92ae-3fb9a7950f2f" Version="2.3.1.2" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1.0000" />
      <ObjectData Name="Scene" Tag="140" ctype="GameNodeObjectData">
        <Size X="960.0000" Y="640.0000" />
        <Children>
          <AbstractNodeData Name="Background" ActionTag="-814358314" Tag="50" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-187.0000" RightMargin="-187.0000" TopMargin="-110.0000" ctype="SpriteObjectData">
            <Size X="1334.0000" Y="750.0000" />
            <Children>
              <AbstractNodeData Name="ScrollViewSeparator" ActionTag="-582520858" Tag="29" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="-1.0000" RightMargin="-1.0000" TopMargin="508.0000" BottomMargin="208.0000" ctype="SpriteObjectData">
                <Size X="1336.0000" Y="34.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="667.0000" Y="225.0000" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition X="0.5000" Y="0.3000" />
                <PreSize X="1.0015" Y="0.0453" />
                <FileData Type="Normal" Path="Images/ScrollViewSeparator@2x.png" Plist="" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint ScaleX="0.5000" />
            <Position X="480.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" />
            <PreSize X="1.1833" Y="1.2000" />
            <FileData Type="Normal" Path="Images/Background@2x.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="StageSelectLabel" ActionTag="-742054735" Tag="55" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="306.0000" RightMargin="306.0000" TopMargin="28.8000" BottomMargin="555.2000" LabelText="STAGE SELECT" ctype="TextBMFontObjectData">
            <Size X="348.0000" Y="56.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="1.0000" />
            <Position X="480.0000" Y="611.2000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.9550" />
            <PreSize X="0.3625" Y="0.0875" />
            <LabelBMFontFile_CNB Type="Normal" Path="Fonts/Menlo48.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="PageView" ActionTag="976816482" Tag="143" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" TouchEnable="True" BackColorAlpha="102" ColorAngle="90.0000" ScrollDirectionType="0" ctype="PageViewObjectData">
            <Size X="960.0000" Y="640.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="320.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="1.0000" Y="1.0000" />
            <SingleColor A="255" R="150" G="150" B="100" />
            <FirstColor A="255" R="150" G="150" B="100" />
            <EndColor A="255" R="255" G="255" B="255" />
            <ColorVector ScaleY="1.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="BackButton" ActionTag="-809582627" Tag="89" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="96.0000" RightMargin="792.0000" TopMargin="28.8000" BottomMargin="567.2000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="42" Scale9Height="22" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="72.0000" Y="44.0000" />
            <AnchorPoint ScaleY="1.0000" />
            <Position X="96.0000" Y="611.2000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.1000" Y="0.9550" />
            <PreSize X="0.0750" Y="0.0688" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="Images/BackButtonPushed@2x.png" Plist="" />
            <NormalFileData Type="Normal" Path="Images/BackButtonNormal@2x.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="EndlessButton" ActionTag="-2101526217" Tag="9" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="430.0000" RightMargin="430.0000" TopMargin="470.0000" BottomMargin="64.0000" TouchEnable="True" FontSize="14" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="70" Scale9Height="84" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="100.0000" Y="106.0000" />
            <AnchorPoint ScaleX="0.5000" />
            <Position X="480.0000" Y="64.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.1000" />
            <PreSize X="0.1042" Y="0.1656" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="Images/TmpButtonPushed@2x.png" Plist="" />
            <NormalFileData Type="Normal" Path="Images/TmpButtonNormal@2x.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="EndlessLabel" ActionTag="-2053584794" Tag="67" IconVisible="False" PositionPercentXEnabled="True" PositionPercentYEnabled="True" LeftMargin="431.0000" RightMargin="431.0000" TopMargin="594.0000" BottomMargin="18.0000" LabelText="ENDLESS" ctype="TextBMFontObjectData">
            <Size X="98.0000" Y="28.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="480.0000" Y="32.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.0500" />
            <PreSize X="0.1021" Y="0.0437" />
            <LabelBMFontFile_CNB Type="Normal" Path="Fonts/CircleFont24.fnt" Plist="" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>