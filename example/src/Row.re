[@react.component]
let make = (~rowProps: ReasonWindow.FixedSizeList.rowProps) => {
    <div style=(rowProps.style)>(ReasonReact.string("dede"))</div>
}
    